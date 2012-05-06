//
//  tw_float.h
//  DeathHold
//
//  Created by Yacine Sebti on 05/05/12.
//  Copyright (c) 2012 imal. All rights reserved.
//
#pragma once
#ifndef DeathHold_tw_float_h
#define DeathHold_tw_float_h


#include "ofxTweenzor.h"

class tw_float
{
public:
    float twf;
    
    tw_float(){
        twf = 0;
    }
    
    void set(float float_to_set) {
        twf = float_to_set;
        Tweenzor::add( &twf, float_to_set, float_to_set, 0,1, EASE_LINEAR );
    }
    
    void set(float float_to_set, int duration) {
        Tweenzor::add( &twf, twf, float_to_set, 0, duration, EASE_LINEAR );
    }
    
    void set(float float_to_start_from, float float_to_set, int duration) {
        twf = float_to_start_from;
        Tweenzor::add( &twf, float_to_start_from, float_to_set, 0, duration, EASE_LINEAR );
    }
    
    void set( float float_to_set, int duration, int EASE_curve) {
        Tweenzor::add( &twf, twf, float_to_set, 0,duration, EASE_curve );
    }
    
    
    void set(float float_to_start_from, float float_to_set, int duration, int EASE_curve) {
        twf = float_to_start_from;
        Tweenzor::add( &twf, float_to_start_from, float_to_set, 0,duration, EASE_curve );
    }
    
    


};


#endif
