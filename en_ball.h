#pragma once

#include "base_object.h"
#define EN_BALL_RADIUS			ofGetWidth()/50 //20
#define EN_BALL_SPEED           ofGetWidth()/100 //10


class en_ball : public base_object {
public:
	ofPoint pos;
	ofPoint vel;
	ofColor col;
	
	//----------------------------------------------------------------	
	void init(int id) {
		pos.set(ofRandomWidth(), ofRandomHeight(), 0);
		float theta = ofRandom(0, 360);
        vel.set(EN_BALL_SPEED * cos(theta), EN_BALL_SPEED * sin(theta), 0);
		
		
		col.set( 255, 50, 50, 255 );
        
		
        
		
	}
	
	//----------------------------------------------------------------	
    void update() {

        // add vel to pos
        pos.x += vel.x * en_velfactor;
        pos.y += vel.y * en_velfactor;

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
	void draw() {
            ofSetColor(col);		
			ofCircle(pos.x, pos.y, EN_BALL_RADIUS);
	}
	
	//----------------------------------------------------------------	
	void moveTo(int x, int y) {
		pos.set(x, y, 0);
		vel.set(0, 0, 0);
	}

    //----------------------------------------------------------------	
	bool check_ring_collision(float x, float y) {
        if ( pow((pos.x-x),2)+pow((pos.y-y),2) < pow((float)TOUCH_RING_RADIUS,2) ){
            return true;
        }
        return false;
    }
            
};
