//
//  shockwave.h
//  DeathHold
//
//  Created by Al Kaos on 5/4/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#pragma once

#include "we_shockwave.h"


class ch_we_shockwave : public we_shockwave
{
public:
    
    tw_float alpha;


    ch_we_shockwave() {
        
		
		col.set( 50.0, 50.0, 255.0, 0 );
        
       
        alive = false;        
    }
    
    void expansion() {
        
        alive = true;
        radius.twf = 0;
        radius.delayedset(1,TOUCH_SHOCKWAVE_MAX_RADIUS,1,4);
        alpha.set(255);
        radius.set( 1.0f, RING_RADIUS*10.0f,4.0f);
    }
    
    void update() {
        
    }
    
    void draw(ofStyle fill) {
        ofPushStyle();
        ofSetStyle(fill);	
        col.a = (int)(alpha.twf);
        ofSetColor(col);		
        ofCircle(pos.x, pos.y, radius.twf);
        ofPopStyle();
	}
    
    void die() {
        
        alive = false;
        alpha.delayedset(0,0.3,0.1);
        radius.set(radius.twf);
        
    }
    void diefast() {
        
        alive = false;
        alpha.set(0);
        radius.set(radius.twf);
        
    }
    
    void moveTo(int x, int y) {
        pos.set(x,y,0);
    }
    
    
    
        
    
};