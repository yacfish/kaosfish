#pragma once
#define RING_RADIUS			ofGetWidth()/34 //30
#define TOUCH_RING_RADIUS   ofGetWidth()/25 //40
#define TOUCH_SHOCKWAVE_MAX_RADIUS   ofGetWidth()/6 //170
#define EN_BALL_RADIUS			ofGetWidth()/50 //20
#define EN_BALL_SPEED           ofGetWidth()/70 //10


#include "ofxTweenzor.h"

class base_object
{
public:
    ofPoint pos;
    ofPoint vel;
    ofColor col;
    float velfactor;
    float radius;
    bool alive;
    
    
    void init(int id) {
    }
    
    void update() {
        
    }
    
    void draw() {
        
        ofSetColor(col);		
        ofCircle(pos.x, pos.y, radius);
	}
    
    void moveTo(int x, int y) {
    }
};
