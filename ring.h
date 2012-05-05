#pragma once

#include "base_object.h"



class ring : public base_object {
public:
	ofColor touchCol;
	bool dragged;
	float chargecounter;

	//----------------------------------------------------------------	
	void init() {
        
		pos.set(ofGetWidth()/2, ofGetHeight()/2, 0);
		
		col.set( 50.0f, 50.0f, 255.0f, 120.0f );
        
        touchCol.set( 50.0f, 50.0f, 255.0f, 255.0f );
				
		dragged = false;
        Tweenzor::add( &chargecounter, 0.0f,0.0f, 0.0f,0.0f, EASE_LINEAR );
        
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
