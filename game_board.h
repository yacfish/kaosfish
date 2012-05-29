//
//  board.h
//  DeathHold
//
//  Created by Yacine Sebti on 03/05/12.
//  Copyright (c) 2012 imal. All rights reserved.
//
#pragma once



#include "base_object.h"
#include "ring.h"
#include "en_ball.h"
#include "bg.h"
#include "ch_we_shockwave.h"


class game_board {
public:
    
    bg the_bg;
    we_shockwave one_ring_shockwave;
    ch_we_shockwave one_ring_ch_shockwave;
    ring one_ring;
	vector <en_ball> enemy_list;
    tw_float master_velfactor;
    float level;
    float enemy_count;
    float closest_enemy;
    tw_float elapsed;
    bool started;
    bool show_level;
    bool show_lives;
    bool show_gameover;
    
    //-----------------------------
    
    void init() {
        
        show_level= false;
        show_lives= false;
        started = false;
        elapsed.set(0);
        the_bg.init(level);
        master_velfactor.set(0, 1);
        one_ring.current_life_count = 5;
        one_ring.init();
        level = 1;
        enemy_list.assign(12, en_ball());
        
        for(int i=0; i<enemy_list.size(); i++){
            
            enemy_list[i].init(level);
            
        }
        
        
    }
    
    //-----------------------------
    
    void reinit(float fake) {
        
        
        
        the_bg.init(level);
        one_ring.init();
        
        for(int i=0; i<enemy_list.size(); i++){
            enemy_list[i].reinit(level);
        }
        
        
    }

    
    //-----------------------------
    
    void update() {
        the_bg.update();
        
        one_ring.update();
        
        one_ring_ch_shockwave.moveTo(one_ring.pos.x, one_ring.pos.y);
        
        bool break_bool = false;
        for(int i=0; i < enemy_list.size(); i++){
            
                
                enemy_list[i].velfactor.set(master_velfactor.twf);
                enemy_list[i].update(one_ring.pos.x,one_ring.pos.y);
                
            if (break_bool == false) {
                
                if (enemy_list[i].alive && one_ring.alive) {
                    
                    if (enemy_list[i].check_ring_collision(one_ring.pos.x, one_ring.pos.y, one_ring.radius.twf)) {
                        
                        
                        break_bool = true;
                        one_ring.current_life_count--;
                        one_ring_ch_shockwave.diefast();
                        master_velfactor.set(0, 1.);
                        Tweenzor::getTween( &master_velfactor.twf )->addListener( Tween::COMPLETE, this, &game_board::reinit );
                        
                        for(int i=0; i < enemy_list.size(); i++){
                             enemy_list[i].alpha.set(0, 0.7);
                         }
                        one_ring.alive = false;
                        
                        if (one_ring.current_life_count>0) {
                            show_lives = true;
                        }else{
                            show_gameover = true;
                        }
                        
                        
                        
                        
                        
                    }
                }
                
                if (one_ring_shockwave.alive == true) {
                    
                    if (one_ring_shockwave.check_weapon_collision(enemy_list[i].pos.x, enemy_list[i].pos.y)) {
                        
                        enemy_list[i].die();
                                                    
                    }
                    
                }
            
            }
            
        }
        enemy_count= 0;
        for(int i=0; i < enemy_list.size(); i++){
            if (enemy_list[i].alive) {
               
                enemy_count++;
            }
        }
        if (enemy_count == 0){
            level++;
            one_ring_shockwave.die();
            reinit(level);
            one_ring.dragged = false;
            show_level = true;
        }
        closest_enemy = 1000000;
        for(int i=0; i < enemy_list.size(); i++){
            if (enemy_list[i].alive) {
                float ball_ring_dist = enemy_list[i].distance_from(one_ring.pos.x, one_ring.pos.y);
                if (ball_ring_dist < closest_enemy) {
                    closest_enemy = ball_ring_dist;
                }
            }
        }
    }
    
    //-----------------------------
    
    void draw( ofStyle fill) {
        
    
        one_ring_ch_shockwave.draw(fill);
        
        the_bg.draw(level,enemy_count,closest_enemy, elapsed.twf, master_velfactor.twf, EN_BALL_RADIUS ,one_ring.radius.twf, one_ring.current_life_count);
        
        one_ring.draw();
        
        for(int i = 0; i< enemy_list.size(); i++){
            
            enemy_list[i].draw();
            
        }
        
        one_ring_shockwave.draw();
        
        
        
    }
    
    //-----------------------------
    
    void touchdown1(int x, int y) {
        if (!started) {
            elapsed.setcurve(0, 660 ,660.0f, EASE_LINEAR );
            started = true;
        }
        
        if ( pow((x-one_ring.pos.x),2)+pow((y-one_ring.pos.y),2) < pow((float)TOUCH_RING_RADIUS*1.5,2) ) {
            one_ring.alive = true;
            one_ring.moveTo(x, y);
            one_ring.dragged = true;
            master_velfactor.setcurve( 1, 1 , EASE_IN_OUT_SINE);
            one_ring_ch_shockwave.expansion();
            
            
        }
    }
    
    //-----------------------------
    
    void touchmoved1(int x, int y) {
        
        if (one_ring.dragged == true) {
            
            one_ring.moveTo(x, y);
            one_ring.dragged = true;

        }else{
            if (one_ring.alive) {
                
                touchdown1(x,y);
                
            }
            
        }
        
    }    
    
    //-----------------------------
    
    void touchup1(int x, int y) {
        
        if (one_ring.dragged && one_ring.alive) {
            
            master_velfactor.setcurve( 0.2f , 0.3f , EASE_IN_OUT_SINE );
            
            one_ring_shockwave.expansion(one_ring.pos.x, one_ring.pos.y, one_ring_ch_shockwave.radius.twf);
            
            one_ring_ch_shockwave.die();
            
            one_ring.touchup();
            
            
        }
        
    } 
    
    //-----------------------------

    
    void die(){
        
        
    }
};