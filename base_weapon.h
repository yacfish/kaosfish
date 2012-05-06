//
//  base_weapon.h
//  DeathHold
//
//  Created by Al Kaos on 5/4/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "base_object.h"


class base_weapon : public base_object
{
public:
    
    ofPoint vel;
    
    bool check_weapon_collision(float x, float y) {
        if ( pow((pos.x-x),2)+pow((pos.y-y),2) < pow((float)radius.twf+EN_BALL_RADIUS,2) ){
            return true;
        }
        return false;
    }
    
    
};

