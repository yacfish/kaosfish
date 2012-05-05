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
    float duration;
       
    tw_float(){
        twf = 0;
        duration = 0;
    }
    
    void set(float float_to_set) {
        Tweenzor::add( &twf, twf, float_to_set, 0,1, EASE_LINEAR );
    }
    
    void set(float float_to_set, float duration) {
        Tweenzor::add( &twf, twf, float_to_set, 0, (int)duration, EASE_LINEAR );
    }
    
    void set(float float_to_start_from, float float_to_set, float duration) {
        Tweenzor::add( &twf, float_to_start_from, float_to_set, 0, (int)duration, EASE_LINEAR );
    }
    
    


};


#endif
