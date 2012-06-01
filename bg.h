//
//  bg.h
//  DeathHold
//
//  Created by Yacine Sebti on 03/05/12.
//  Copyright (c) 2012 imal. All rights reserved.
//

#pragma once

#include "base_object.h"
//#include <iostream>

class bg : public base_object {
public:
    
    
    float dh_offset;
    float fps_offset;
    float level_offset;
    float en_cnt_offset;
    float closest_enemy_offset;
    float dh_vel;
    float fps_vel;
    float level_vel;
    float en_cnt_vel;
    float closest_enemy_vel;
    float dh_pos;
    float fps_pos;
    float level_pos;
    float en_cnt_pos;
    float closest_enemy_pos;
    string time_left;

    
	//----------------------------------------------------------------	
	void init(float level) {
//		dh_offset = ofRandom(0.0f, 200.0f);
//        fps_offset = ofRandom(0.0f, 200.0f);
//        level_offset = ofRandom(0.0f, 200.0f);
//        en_cnt_offset = ofRandom(0.0f, 200.0f);
//        closest_enemy_offset = ofRandom(0.0f, 200.0f);

        dh_offset = 20;
        fps_offset = 20;
        level_offset = 20;
        en_cnt_offset = 20;
        closest_enemy_offset = 20;

      	col.set( 50.0f, 50.0f, 50.0f, 120.0f );

//        dh_vel = ofRandom(1.0f, 3.0f);
//        fps_vel = ofRandom(1.0f, 3.0f);
//        level_vel = ofRandom(1.0f, 3.0f);
//        en_cnt_vel = ofRandom(1.0f, 3.0f);
//        closest_enemy_vel = ofRandom(1.0f, 3.0f);
//        
        dh_vel = 0;
        fps_vel =0;
        level_vel =0;
        en_cnt_vel =0;
        closest_enemy_vel =0;
        

      	col.set( 50.0f, 50.0f, 50.0f, 120.0f );
        
	}
	
	//----------------------------------------------------------------	
    void update() {
        
        
        dh_offset = dh_offset + dh_vel;
        fps_offset = fps_offset + fps_vel;
        level_offset = level_offset + level_vel;
        en_cnt_offset = en_cnt_offset + en_cnt_vel;
        closest_enemy_offset = closest_enemy_offset + closest_enemy_vel;

        
//        rajouter modulo
//        if (dh_offset > 0) {
//            dh_offset = dh_offset - 400;
//        } 
//        if (fps_offset > 0) {
//            fps_offset = fps_offset - 400;
//        }
//        if (level_offset > 0) {
//        level_offset = level_offset - 400;
//        }
//        if (en_cnt_offset > 0) {
//        en_cnt_offset = en_cnt_offset - 400;
//        }
//        if (closest_enemy_offset > 0) {
//        closest_enemy_offset = closest_enemy_offset - 400;
//        }
        
        
        
      	col.set( 50.0f, 50.0f, 50.0f, 120.0f );

       	}
    
	
	//----------------------------------------------------------------
    
    void draw(int level, float enemy_count, float closest_enemy, float elapsed, float velfact,float en_rad, float ri_rad, int life_count) {
        
        ofSetColor(col);		
        ofCircle(pos.x, pos.y, radius.twf);
        
        if (elapsed > 300){
            elapsed = 300;
        }
        elapsed = 300 - elapsed;
        ofSetColor(150,150,150);
        
        int minute= elapsed/ 60;
        float secondf= (int)((elapsed/ 60- minute)*60);
        int second= (int)secondf;
        stringstream mm;
        mm << setw(2) << setfill('0') << (int)minute;
        string formatted_minutes = mm.str();
        stringstream ss;
        ss << setw(2) << setfill('0') << (int)second;
        string formatted_seconds = ss.str();
        time_left = formatted_minutes + ":" + formatted_seconds;
        
       float closest_enemy_dist = pow((float)closest_enemy,(float)0.5)-(en_rad+ri_rad);
        
        for (int i=1; i < 2; i++ ) {
            for (int j=1; j < 2; j++ ) {
                
                ofSetColor(100,100,100,255);
                ofDrawBitmapString("death hold", (int)dh_offset+(i * 200), 20+(j * 385));
                ofDrawBitmapString("fps:" + ofToString(ofGetFrameRate(), 2), (int)(fps_offset+(i * 200)), 75+(j * 385));
                ofDrawBitmapString("level:" + ofToString(level) , (int)level_offset+(i * 200), 130+(j * 385));
                ofDrawBitmapString("enemy_count:" + ofToString(enemy_count) , en_cnt_offset+(i * 200), 185+(j * 385));
            
                float red= 100;
                if (closest_enemy_dist < 200) {
                    red = (((200 - closest_enemy_dist)/100) * 155 ) + 100;
                }
                
                ofSetColor(red,100,100,255);
                
                ofDrawBitmapString("closest_enemy_dist:" + ofToString((int)closest_enemy_dist) , (int)(closest_enemy_offset+(i * 200)), 240+(j * 385));
               
                ofSetColor(100,100,100,255);
                
                ofDrawBitmapString("life_count: " + ofToString(life_count), (int)20+(i * 200), 295+(j * 385));

                
                ofDrawBitmapString(formatted_minutes + ":" + formatted_seconds, (int)20+(i * 200), 350+(j * 385));
//                ofDrawBitmapString(formatted_minutes + ":" + formatted_seconds, (int)120+(i * 200), 350+(j * 385));
            }
        }
    }
    
	
	//----------------------------------------------------------------	
    
    
    
	
	//----------------------------------------------------------------	
    
    
    
    
};

//
//ofDrawBitmapString("death hold", 10, 20);
//ofDrawBitmapString("fps:" + ofToString(fps, 2) , 10, 50);
//ofDrawBitmapString("level:" + ofToString(big_board.level) , 10, 80);
//ofDrawBitmapString("enemy_count:" + ofToString(big_board.enemy_count) , 10, 110);
//ofDrawBitmapString("closest_enemy_dist:" + ofToString((int)pow((float)big_board.closest_enemy,(float)0.5)) , 10, 140);
