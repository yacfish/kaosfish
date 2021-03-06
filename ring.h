#pragma once

#include "base_object.h"



class ring : public base_object {
public:
	ofColor touchCol;
	bool dragged;
	
    int current_life_count;
    tw_float destruct_timer;
    float auto_destruct_time;

	//----------------------------------------------------------------	
	void init() {
        
		pos.set(ofGetWidth()/2, ofGetHeight()/2, 0);
		
		col.set( 50.0f, 50.0f, 255.0f, 120.0f );
        
        touchCol.set( 50.0f, 50.0f, 255.0f, 255.0f );
        
		dragged = false;
        
        
        alive = false;
        dragged = false;
        
        auto_destruct_time = 2;
         
	}
	
	//----------------------------------------------------------------	
    void update() {
        if( dragged ){
			radius.set(TOUCH_RING_RADIUS);
		}else{
			radius.set(RING_RADIUS);
		}

	}
	
	//----------------------------------------------------------------
	void draw() {
        ofSetColor(touchCol);
        ofCircle(pos.x, pos.y, radius.twf);
    }
    void moveTo(int x, int y) {
        pos.set(x,y,0);
    }
    void touchup(){
        
        dragged = false;
        destruct_timer.set(0, (int)auto_destruct_time*ofGetFrameRate(), (int)auto_destruct_time*ofGetFrameRate());
        
        
    }
};
