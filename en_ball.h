#pragma once

#include "base_enemy.h"


class en_ball : public base_enemy {
public:
    
    float alpha;

		
	//----------------------------------------------------------------	
	void init(float level) {
		
        if (ofRandom(0, 2) > 1) {
            pos.set((int)(ofRandom(1)+0.5)*ofGetWidth(), ofRandomHeight(), 0);
        }else{
            pos.set(ofRandomWidth(), (int)(ofRandom(1)+0.5) * ofGetHeight(), 0);
        }
        
        float theta = ofRandom(0, 360);
        vel.set(EN_BALL_SPEED * ((level-1)*0.05+1) * cos(theta), EN_BALL_SPEED * ((level-1)*0.05+1) * sin(theta), 0);
		
		radius = EN_BALL_RADIUS;
        alive = true;
		col.set( 255.0f, 50.0f, 50.0f, 255.0f );
        
		velfactor = 0;
        
        //alpha = 255;
        
        Tweenzor::add( &alpha, alpha, 255, 0,1, EASE_IN_OUT_SINE);
		
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
   
    void draw() {
        col.a = (int)alpha;
        ofSetColor(col);		
        ofCircle(pos.x, pos.y, radius);
	}

	
	//----------------------------------------------------------------	
    
    
	void moveTo(int x, int y) {
        
		pos.set(x, y, 0);
		vel.set(0, 0, 0);
        
	}
    
	
	//----------------------------------------------------------------	
    
    
    void die(float fps){
        
        alive = false;
        Tweenzor::add( &alpha, alpha, 0, 0,(int)(0.1 * fps), EASE_IN_OUT_SINE);
        
    }
    
};
