#pragma once

#include "base_enemy.h"


class en_ball : public base_enemy {
public:
    
    tw_float alpha;

		
	//----------------------------------------------------------------	
	void init(float level) {
		
        if (ofRandom(0, 2) > 1) {
            pos.set((int)(ofRandom(1)+0.5)*ofGetWidth(), ofRandomHeight(), 0);
        }else{
            pos.set(ofRandomWidth(), (int)(ofRandom(1)+0.5) * ofGetHeight(), 0);
        }
        
        float theta = ofRandom(0, 360);
        vel.set(EN_BALL_SPEED * ((level-1)*0.05+1) * cos(theta), EN_BALL_SPEED * ((level-1)*0.05+1) * sin(theta), 0);
		
		radius.set(EN_BALL_RADIUS);
        alive = true;
		col.set( 255.0f, 50.0f, 50.0f, 255.0f );
        
		velfactor.set(0);
        
        //alpha = 255;
        
        alpha.set(255);
		
	}
	
	//----------------------------------------------------------------	
    void update() {

        // add vel to pos
        pos.x += vel.x * velfactor.twf;
        pos.y += vel.y * velfactor.twf;

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
        col.a = (int)alpha.twf;
        ofSetColor(col);		
        ofCircle(pos.x, pos.y, radius.twf);
	}

	
	//----------------------------------------------------------------	
    
    
	void moveTo(int x, int y) {
        
		pos.set(x, y, 0);
		vel.set(0, 0, 0);
        
	}
    
	
	//----------------------------------------------------------------	
    
    
    void die(float fps){
        
        alive = false;
        alpha.set( 0,(int)(0.1 * fps));
        
    }
    
};
