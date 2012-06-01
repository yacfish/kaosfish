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
    
    tw_float alpha;
    

    we_shockwave() {
        
		
		col.set( 50.0, 50.0, 255.0, 0 );
        
       
        alive = false;        
    }
    
    void expansion(float x, float y,float charge) {
        
        alive = true;
        pos.x = x;
        pos.y = y;
        
        alpha.set(120);
        
        if (charge > 0){
            radius.set(RING_RADIUS, charge, 0.3);
            Tweenzor::getTween( &radius.twf )->addListener( Tween::COMPLETE, this, &we_shockwave::die );
          
        }
    }
    
    void update() {
        
    }
    
    void draw() {
        col.a = (int)alpha.twf;
        ofSetColor(col);		
        ofCircle(pos.x, pos.y, radius.twf);
	}
    
    void die(float f) {
        
        alive = false;
        alpha.set( 0, 0.1);
        
    }
  
    void die() {
        
        alive = false;
        alpha.set( 0, 0.1);
        
    }

    
};