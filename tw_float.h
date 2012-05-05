//
//  tw_float.h
//  DeathHold
//
//  Created by Yacine Sebti on 05/05/12.
//  Copyright (c) 2012 imal. All rights reserved.
//

#ifndef DeathHold_tw_float_h
#define DeathHold_tw_float_h


#include "ofxTweenzor.h"

class tw_float
{
public:
    float f;
    float duration;
       
    
    void set(float float_to_set) {
        Tweenzor::add( &f, f, float_to_set, 0,0, EASE_LINEAR );
    }
    


};


#endif
