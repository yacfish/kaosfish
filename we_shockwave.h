//
//  shockwave.h
//  DeathHold
//
//  Created by Al Kaos on 5/4/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#pragma once

#include "base_weapon.h"


class we_shockwave : public base_weapon
{
public:
    
    float alpha;
    float charge_factor;

    we_shockwave() {
        
		
		col.set( 50.0, 50.0, 255.0, 120.0 );
        
       
        alive = false;        
    }
    
    void expansion(float x, float y,float charge, float fps) {
        
        alive = true;
        pos.x = x;
        pos.y = y;
        charge_factor = charge;
        Tweenzor::add( &radius, RING_RADIUS, RING_RADIUS*charge_factor, 0,(int)(0.3 * fps), EASE_IN_OUT_SINE );
        Tweenzor::getTween( &radius )->addListener( Tween::COMPLETE, this, &we_shockwave::die );
    }
    
    void update() {
        
    }
    
    void draw() {
        col.a = alpha;
        ofSetColor(col);		
        ofCircle(pos.x, pos.y, radius);
	}
    
    void die(float fps) {
        
        alive = false;
        Tweenzor::add( &alpha, 255, 0, 0,(int)(0.5 * fps), EASE_IN_OUT_SINE);
        
    }
    
        
    
};