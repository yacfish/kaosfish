//
//  board.h
//  DeathHold
//
//  Created by Yacine Sebti on 03/05/12.
//  Copyright (c) 2012 imal. All rights reserved.
//
#pragma once

#include "ofxTweenzor.h"

#include "base_object.h"
#include "ring.h"
#include "en_ball.h"
#include "bg.h"


class board {
public:
    
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
        
        for(int i=0; i < balls.size(); i++){
            
            balls[i].en_velfactor = velfactor;
            balls[i].update();
            if (balls[i].check_ring_collision(one_ring.pos.x, one_ring.pos.y) == true) {
                //reinit
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
        
        ofPopStyle();
        
    }
    
    //-----------------------------
    
    void touchdown1(int x, int y, float fps) {
        
        if ( pow((x-one_ring.pos.x),2)+pow((y-one_ring.pos.y),2) < pow((float)TOUCH_RING_RADIUS*1.5,2) ) {
            
            one_ring.moveTo(x, y);
            one_ring.bDragged = true;
            Tweenzor::add( &velfactor, velfactor, 1, 0,(int)(1 * fps), EASE_IN_OUT_SINE );
        }
    }
    
    //-----------------------------
    
    void touchmoved1(int x, int y,float fps) {
        
        if (one_ring.bDragged == true) {
            
            one_ring.moveTo(x, y);
            one_ring.bDragged = true;

        }else{
            touchdown1(x,y,fps);
        }
        
    }    
    
    //-----------------------------
    
    void touchup1(int x, int y, float fps) {
        
        if (one_ring.bDragged == true) {
            one_ring.bDragged = false;
            Tweenzor::add( &velfactor, velfactor, 0.2, 0,(int)(0.3 * fps), EASE_IN_OUT_SINE );
        }
        
    } 
};