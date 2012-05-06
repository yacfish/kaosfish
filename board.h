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

class board {
public:
    bg the_bg;
    we_shockwave one_ring_shockwave;
    ch_we_shockwave one_ring_ch_shockwave;
    ring one_ring;
	vector <en_ball> balls;
    tw_float master_velfactor;
    float level;
    //float del;
    float enemy_count;
    float closest_enemy;
    float elapsed;
    
    
    //-----------------------------
    
    void init() {
        
        Tweenzor::add( &elapsed, 0, 660, 0.0f,660.0f, EASE_LINEAR );
        the_bg.init(level);
        master_velfactor.set(0);
        one_ring.init();
        level = 1;
        balls.assign(15, en_ball());
        
        for(int i=0; i<balls.size(); i++){
            balls[i].init(level);
            
            

        }
        
        
    }
    
    //-----------------------------
    
    void reinit() {
        
        master_velfactor.set(0);
        
        the_bg.init(level);
        one_ring.init();
        
        for(int i=0; i<balls.size(); i++){
            balls[i].init(level);
        }
        
        
    }

    
    //-----------------------------
    
    void update(float fps) {
        the_bg.update();
        
        one_ring.update();
        
        one_ring_ch_shockwave.radius.set(one_ring.chargecounter.twf);
        
        bool break_bool = false;
        for(int i=0; i < balls.size(); i++){
            
            if (break_bool == false) {
                
                balls[i].velfactor.set(master_velfactor.twf);
                balls[i].update();
                
                if (balls[i].alive == true) {
                    
                    if (balls[i].check_ring_collision(one_ring.pos.x, one_ring.pos.y, one_ring.radius.twf) == true) {
                        
                        reinit();
                        break_bool = true;
                        one_ring.alive = false;
                        one_ring.current_life_count--;
                        
                    }
                }
                
                if (one_ring_shockwave.alive == true) {
                    
                    if (one_ring_shockwave.check_weapon_collision(balls[i].pos.x, balls[i].pos.y)) {
                        
                        balls[i].die(fps);
                                                    
                    }
                    
                }
            
            }
            
        }
        enemy_count= 0;
        for(int i=0; i < balls.size(); i++){
            if (balls[i].alive) {
                enemy_count++;
            }
        }
        if (enemy_count == 0){
            level++;
            one_ring_shockwave.die(fps);
            reinit();
            one_ring.dragged = false;
        }
        closest_enemy = 1000000;
        for(int i=0; i < balls.size(); i++){
            if (balls[i].alive) {
                float ball_ring_dist = balls[i].distance_from(one_ring.pos.x, one_ring.pos.y);
                if (ball_ring_dist < closest_enemy) {
                    closest_enemy = ball_ring_dist;
                }
            }
        }
    }
    
    //-----------------------------
    
    void draw(float fps, ofStyle fill) {
        
        ofEnableAlphaBlending();
        
        one_ring_ch_shockwave.draw(fill);
        
        the_bg.draw(fps, level,enemy_count,closest_enemy, elapsed, master_velfactor.twf);
        
        one_ring.draw();
        
        for(int i = 0; i< balls.size(); i++){
            
            balls[i].draw();
            
        }
        
        one_ring_shockwave.draw();
        
        ofDisableAlphaBlending();
        
        
    }
    
    //-----------------------------
    
    void touchdown1(int x, int y, float fps) {
        
        if ( pow((x-one_ring.pos.x),2)+pow((y-one_ring.pos.y),2) < pow((float)TOUCH_RING_RADIUS*1.5,2) ) {
            one_ring.alive = true;
            one_ring.moveTo(x, y);
            one_ring.dragged = true;
            master_velfactor.set( master_velfactor.twf, 1.0f , (int)(1 * fps) , EASE_IN_OUT_SINE);
            one_ring.chargecounter.set( 1.0f, 10.0f,(int)(2 * fps));
            
        }
    }
    
    //-----------------------------
    
    void touchmoved1(int x, int y,float fps) {
        
        if (one_ring.dragged == true) {
            
            one_ring.moveTo(x, y);
            one_ring.dragged = true;

        }else{
            if (one_ring.alive) {
                
                touchdown1(x,y,fps);
                
            }
            
        }
        
    }    
    
    //-----------------------------
    
    void touchup1(int x, int y, float fps) {
        
        if (one_ring.dragged == true) {
            
            one_ring.dragged = false;
            
        
            master_velfactor.set( 0.2f , (int)(0.3 * fps) , EASE_IN_OUT_SINE );
            one_ring_shockwave.expansion(one_ring.pos.x, one_ring.pos.y, one_ring.chargecounter.twf, fps);
            one_ring.chargecounter.set(0.0f);
            

        }
        
    } 
    
    //-----------------------------

    
    void die(){
        
        
    }
};