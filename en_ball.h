#pragma once

#include "base_enemy.h"


class en_ball : public base_enemy {
public:
		
	//----------------------------------------------------------------	
	void init(int id) {
		pos.set(ofRandomWidth(), ofRandomHeight(), 0);
		float theta = ofRandom(0, 360);
        vel.set(EN_BALL_SPEED * cos(theta), EN_BALL_SPEED * sin(theta), 0);
		
		radius = EN_BALL_RADIUS;
        alive = true;
		col.set( 255.0f, 50.0f, 50.0f, 255.0f );
        
		velfactor = 0;
        
		
	}
	
	//----------------------------------------------------------------	
    void update() {

        // add vel to pos
        pos.x += vel.x * velfactor;
        pos.y += vel.y * velfactor;

        // check boundaries
        if(pos.x < EN_BALL_RADIUS) {
            pos.x = EN_BALL_RADIUS;
            vel.x *= -1;
            
        } else if(pos.x >= ofGetWidth() - EN_BALL_RADIUS) {
            pos.x = ofGetWidth() - EN_BALL_RADIUS;
		 	vel.x *= -1;
            
		}
		
		if(pos.y < EN_BALL_RADIUS) {
			pos.y = EN_BALL_RADIUS;
			vel.y *= -1;
		} else if(pos.y >= ofGetHeight() - EN_BALL_RADIUS) {
			pos.y = ofGetHeight() - EN_BALL_RADIUS;
			vel.y *= -1; 
		}
	}
	
	//----------------------------------------------------------------
   
    
	
	//----------------------------------------------------------------	
	void moveTo(int x, int y) {
		pos.set(x, y, 0);
		vel.set(0, 0, 0);
	}
            
};
