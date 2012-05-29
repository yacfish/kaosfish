#pragma once
#define RING_RADIUS                     ofGetWidth()/34 //30
#define TOUCH_RING_RADIUS               ofGetWidth()/25 //40
#define TOUCH_SHOCKWAVE_MAX_RADIUS      ofGetWidth()/5 //170
#define EN_BALL_RADIUS                  ofGetWidth()/40 //20
#define EN_BALL_SPEED                   ofGetWidth()/130 //10


#include "tw_float.h"

class base_object
{
public:
    ofPoint pos;
    
    ofColor col;
    tw_float velfactor;
    tw_float radius;
    bool alive;
    
    
    void update() {
        
    }
    
    void draw() {
        
        ofSetColor(col);		
        ofCircle(pos.x, pos.y, radius.twf);
	}
    
   
    
    float clip(float val,float min, float max){
        if (val < min) {
            return min;
        }
        if (val > max) {
            return max;
        }
        return val;
    }
    
};
