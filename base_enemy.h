//
//  base_enemy.h
//  DeathHold
//
//  Created by Al Kaos on 5/4/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "base_object.h"


class base_enemy : public base_object
{
public:
    
    float ring_dist;
    
    float distance_from(float x, float y){
        ring_dist = pow((pos.x-x),2)+pow((pos.y-y),2);
        return ring_dist;
    }
    
        
    //----------------------------------------------------------------	
	bool check_ring_collision(float x, float y) {
//        if ( pow((pos.x-x),2)+pow((pos.y-y),2) < pow((float)TOUCH_RING_RADIUS+EN_BALL_RADIUS,2) ){
//            return true;
//        }
        return false;
    }

};