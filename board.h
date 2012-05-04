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
#include "we_shockwave.h"

class board {
public:
    
    we_shockwave ring_shockwave;
    ring one_ring;
	vector <en_ball> balls;
    float velfactor;
    
    
    //-----------------------------
    
    void init() {
        
        velfactor = 0;
        one_ring.init();
        
        balls.assign(5, en_ball());
        
        for(int i=0; i<balls.size(); i++){
            balls[i].init(i);
        }
        
        
    }
    
    //-----------------------------
    
    void reinit() {
        
        velfactor = 0;
        one_ring.init();
        
        
        for(int i=0; i<balls.size(); i++){
            balls[i].init(i);
        }
        
        
    }

    
    //-----------------------------
    
    void update() {
        one_ring.update();
        bool break_bool = false;
        for(int i=0; i < balls.size(); i++){
            
            if (break_bool == false) {
                
                balls[i].velfactor = velfactor;
                balls[i].update();
                
                if (balls[i].alive == true) {
                    
                    if (balls[i].check_ring_collision(one_ring.pos.x, one_ring.pos.y) == true) {
                        
                        reinit();
                        break_bool = true;
                        one_ring.alive = false;
                        
                    }
                }
                
                if (ring_shockwave.alive == true) {
                    if (ring_shockwave.check_weapon_collision(balls[i].pos.x, balls[i].pos.y)) {
                        balls[i].alive = false;
                    }
                }
            
                
            }
            
        }
        
        
    }
    
    //-----------------------------
    
    void draw() {
        
        ofPushStyle();
        ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
        
        one_ring.draw();
        for(int i = 0; i< balls.size(); i++){
            balls[i].draw();
        }
        ring_shockwave.draw();
        
        ofPopStyle();
        
    }
    
    //-----------------------------
    
    void touchdown1(int x, int y, float fps) {
        
        if ( pow((x-one_ring.pos.x),2)+pow((y-one_ring.pos.y),2) < pow((float)TOUCH_RING_RADIUS*1.5,2) ) {
            one_ring.alive = true;
            one_ring.moveTo(x, y);
            one_ring.dragged = true;
            Tweenzor::add( &velfactor, velfactor, 1, 0,(int)(1 * fps), EASE_IN_OUT_SINE );
        }
    }
    
    //-----------------------------
    
    void touchmoved1(int x, int y,float fps) {
        
        if (one_ring.dragged == true) {
            
            one_ring.moveTo(x, y);
            one_ring.dragged = true;

        }else{
            if (one_ring.alive) {
                
                one_ring.moveTo(x, y);
                one_ring.dragged = true;
                Tweenzor::add( &velfactor, velfactor, 1, 0,(int)(1 * fps), EASE_IN_OUT_SINE );
                
            }
        }
        
    }    
    
    //-----------------------------
    
    void touchup1(int x, int y, float fps) {
        
        if (one_ring.dragged == true) {
            
            one_ring.dragged = false;
            Tweenzor::add( &velfactor, velfactor, 0.2, 0,(int)(0.3 * fps), EASE_IN_OUT_SINE );
            
            ring_shockwave.expansion(one_ring.pos.x, one_ring.pos.y,10, fps);
            
        }
        
    } 
};