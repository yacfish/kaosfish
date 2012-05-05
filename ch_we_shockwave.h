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
    float charge_factor;

    ch_we_shockwave() {
        
		
		col.set( 50.0, 50.0, 255.0, 0 );
        
       
        alive = false;        
    }
    
    void expansion(float x, float y,float charge, float fps) {
        
        alive = true;
        pos.x = x;
        pos.y = y;
        charge_factor = charge;
        Tweenzor::add( &charge_factor, charge, 0, 0,(int)(0.1 * fps), EASE_IN_OUT_SINE);
        alpha.set(120, 0);
        if (charge_factor > 0){
            Tweenzor::add( &radius, TOUCH_RING_RADIUS, TOUCH_RING_RADIUS * charge_factor, 0,(int)(0.3 * fps), EASE_IN_OUT_SINE );
            Tweenzor::getTween( &radius )->addListener( Tween::COMPLETE, this, &ch_we_shockwave::die );
        }
    }
    
    void update() {
        
    }
    
    void draw(ofStyle fill) {
        ofPushStyle();
        ofSetStyle(fill);	
        col.a = (int)(alpha.twf);
        ofSetColor(col);		
        ofCircle(pos.x, pos.y, radius);
        ofPopStyle();
	}
    
    void die(float fps) {
        
        alive = false;
        alpha.set(0,0.1 * fps);
        
    }
    
        
    
};