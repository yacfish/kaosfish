#pragma once

#include "base_enemy.h"

class en_ball : public base_enemy {
public:
    
    tw_float alpha;
    float enemyrotation;    
    
	//----------------------------------------------------------------	
	void init(float level) {
		
        if (ofRandom(0, 2) > 1) {
            pos.set(((int)(ofRandom(1)+0.5)*ofGetWidth())*0.9+ofGetWidth()*0.05, ofRandomHeight()*0.9+ofGetHeight()*0.05, 0);
        }else{
            pos.set(ofRandomWidth()*0.9+ofGetWidth()*0.05,((int)(ofRandom(1)+0.5))*ofGetHeight()*0.9+ofGetHeight()*0.05, 0);
        }
        
        float theta = ofRandom(0, 360);
        vel.set(EN_BALL_SPEED * ((level-1)*0.05+1) * cos(theta), EN_BALL_SPEED * ((level-1)*0.05+1) * sin(theta), 0);
		
		radius.set(EN_BALL_RADIUS);
        alive = true;
		col.set( 255.0f, 255.0f, 255.0f, 255.0f );
        sprite_enemy.loadImage("images/enemy1_50.png");
        
		velfactor.set(0);
        
        //alpha = 255;
        enemyrotation = 0;
        alpha.set(255);
		
	}
    
    void reinit(float level) {
        
        if (ofRandom(0, 2) > 1) {
            pos.set(((int)(ofRandom(1)+0.5)*ofGetWidth())*0.9+ofGetWidth()*0.05, ofRandomHeight()*0.9+ofGetHeight()*0.05, 0);
        }else{
            pos.set(ofRandomWidth()*0.9+ofGetWidth()*0.05,((int)(ofRandom(1)+0.5))*ofGetHeight()*0.9+ofGetHeight()*0.05, 0);
        }
        
        float theta = ofRandom(0, 360);
        vel.set(EN_BALL_SPEED * ((level-1)*0.05+1) * cos(theta), EN_BALL_SPEED * ((level-1)*0.05+1) * sin(theta), 0);
		
		radius.set(EN_BALL_RADIUS);
        alive = true;
		
        
		velfactor.set(0);
        
        //alpha = 255;
        
        alpha.set(255, 0.7);
        
        
    }
    
    
	
	//----------------------------------------------------------------	
    void update(float x, float y) {
        
        // add vel to pos
        pos.x += vel.x * velfactor.twf * 60/ofGetFrameRate();
        pos.y += vel.y * velfactor.twf * 60/ofGetFrameRate();
        
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
        float dist_factor = 1 - ((clip(sqrt(distance_from(x, y)),0, 400)/ 400)*0.6);
        enemyrotation= (int)((enemyrotation+(10*dist_factor*velfactor.twf*60/ofGetFrameRate())))%360;
        
	}
    
	
	//----------------------------------------------------------------
    
    void draw() {
        col.a = (int)alpha.twf;
        ofSetColor(col);		
        ofPushMatrix ();
        ofTranslate (pos.x, pos.y);
        ofRotate (enemyrotation);
        sprite_enemy.draw(-25,-25);
        ofPopMatrix ();
	}
    
	
	//----------------------------------------------------------------	
    
    
	void moveTo(int x, int y) {
        
		pos.set(x, y, 0);
		vel.set(0, 0, 0);
        
	}
    
	
	//----------------------------------------------------------------	
    
    
    void die(){
        
        alive = false;
        alpha.set( 0,0.1);
        
    }
    
};
