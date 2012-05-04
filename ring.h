#pragma once

#include "base_object.h"
#define RING_RADIUS			ofGetWidth()/34 //30
#define TOUCH_RING_RADIUS   ofGetWidth()/25 //40
#define TOUCH_SHOCKWAVE_MAX_RADIUS   ofGetWidth()/6 //170


class ring : public base_object {
public:
	ofPoint pos;
	ofPoint vel;
	ofColor col;
	ofColor touchCol;
	bool dragged;
	bool alive;

	//----------------------------------------------------------------	
	void init() {
        
		pos.set(ofGetWidth()/2, ofGetHeight()/2, 0);
		
		col.set( 50, 50, 255, 120 );
        
        touchCol.set( 50, 50, 255, 255 );
				
		dragged = false;
        
	}
	
	//----------------------------------------------------------------	
    void update() {
     
	}
	
	//----------------------------------------------------------------
	void draw() {
		if( dragged ){
			ofSetColor(touchCol);
			ofCircle(pos.x, pos.y, TOUCH_RING_RADIUS);
		}else{
			ofSetColor(col);		
			ofCircle(pos.x, pos.y, RING_RADIUS);
		}
	}
	
	//----------------------------------------------------------------	
	void moveTo(int x, int y) {
		pos.set(x, y, 0);
		vel.set(0, 0, 0);
	}
};
