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
    
    void set(float float_to_set, float duration) {
        Tweenzor::add( &twf, twf, float_to_set, 0, (int)(duration*ofGetFrameRate()), EASE_LINEAR );
    }
    
    void set(float float_to_start_from, float float_to_set, float duration) {
        twf = float_to_start_from;
        Tweenzor::add( &twf, float_to_start_from, float_to_set, 0, (int)(duration*ofGetFrameRate()), EASE_LINEAR );
    }
    
    void setcurve( float float_to_set, float duration, int EASE_curve) {
        Tweenzor::add( &twf, twf, float_to_set, 0,(int)(duration*ofGetFrameRate()), EASE_curve );
    }
    
    
    void setcurve(float float_to_start_from, float float_to_set, float duration, int EASE_curve) {
        twf = float_to_start_from;
        Tweenzor::add( &twf, float_to_start_from, float_to_set, 0,(int)(duration*ofGetFrameRate()), EASE_curve );
    }
    void delayedset(float float_to_set, float delay_time) {
        twf = float_to_set;
        Tweenzor::add( &twf, float_to_set, float_to_set, (int)(delay_time*ofGetFrameRate()), 1, EASE_LINEAR );
    }
    
    void delayedset(float float_to_set, float delay_time, float duration) {
        Tweenzor::add( &twf, twf, float_to_set, (int)(delay_time*ofGetFrameRate()), (int)(duration*ofGetFrameRate()), EASE_LINEAR );
    }
    
    void delayedset(float float_to_start_from, float float_to_set, float delay_time, float duration) {
        twf = float_to_start_from;
        Tweenzor::add( &twf, float_to_start_from, float_to_set, (int)(delay_time*ofGetFrameRate()), (int)(duration*ofGetFrameRate()), EASE_LINEAR );
    }
    
    void delayedsetcurve( float float_to_set, float delay_time, float duration, int EASE_curve) {
        Tweenzor::add( &twf, twf, float_to_set, (int)(delay_time*ofGetFrameRate()),(int)(duration*ofGetFrameRate()), EASE_curve );
    }
    
    
    void delayedsetcurve(float float_to_start_from, float float_to_set, float delay_time, float duration, int EASE_curve) {
        twf = float_to_start_from;
        Tweenzor::add( &twf, float_to_start_from, float_to_set, (int)(delay_time*ofGetFrameRate()),(int)(duration*ofGetFrameRate()), EASE_curve );
    }

    
    


};


#endif
