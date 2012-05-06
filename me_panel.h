//
//  me_panel.h
//  DeathHold
//
//  Created by Yacine Sebti on 06/05/12.
//  Copyright (c) 2012 imal. All rights reserved.
//

#ifndef DeathHold_me_panel_h
#define DeathHold_me_panel_h

#include "base_menu.h"


class me_panel : public base_menu
{
public:
    ofPoint rect_size;
    tw_float text_size;
    tw_float alpha;
    tw_float text_alpha;
    tw_float del_val;
    string text;
    ofTrueTypeFont text_show;
    ofColor text_col;
    ofRectangle text_bound;
    bool auto_kill;
    float auto_kill_delay;
    
    
    me_panel(){
        
        auto_kill = false;
        auto_kill_delay = 1;
        
       
    }
    void init(){
         text_show.loadFont("Arial.ttf", ofGetWidth()/10);
    }
    
    void show(string txt, float posx, float posy, float sizex,float sizey){
        
        
        text= txt;
        pos.set(posx, posy);
        alpha.set(200, 0.5);
        text_alpha.set(255);
        
        rect_size.set(sizex, sizey);
        text_size.set(0, 1, 0.5);
        if (auto_kill) {
            
            del_val.set(0, 1, auto_kill_delay);
            Tweenzor::getTween( &del_val.twf )->addListener( Tween::COMPLETE, this, &me_panel::kill_del );
            
            
        }
        
    }
    void show(string txt, float posx, float posy, float sizex,float sizey, float delay){
        
        text= txt;
        pos.set(posx, posy);
        text_alpha.delayedset(255.0f, delay);
        alpha.delayedset(200.0f, delay, 0.5);
        
        rect_size.set(sizex, sizey);
        text_size.delayedset(0, 1, delay, 0.5);
        if (auto_kill) {
            
            del_val.delayedset(0, 1, delay, auto_kill_delay);
            Tweenzor::getTween( &del_val.twf )->addListener( Tween::COMPLETE, this, &me_panel::kill_del );

            
        }
        
    }

    
    void draw(){
        col.set(200,50,50,(int)alpha.twf);
        text_col.set(255,255,255,(int)text_alpha.twf);
        ofSetColor(col);
        ofRect(pos.x - (rect_size.x / 2), pos.y - (rect_size.y / 2),rect_size.x, rect_size.y );
        ofPushMatrix();
        
        text_bound = text_show.getStringBoundingBox(text, 0, 0);
        
        ofTranslate(pos.x-(text_size.twf*(text_bound.width/2)), pos.y+(text_size.twf*text_bound.height/2));
        ofScale(text_size.twf, text_size.twf, 0);
        
        ofSetColor(text_col);
        text_show.drawString(text, 0,0);
        ofPopMatrix();
    }
    
    void kill_del(float fake){
        kill();
    }
    void kill(){
        
        alpha.set(0, 0.2);
        text_size.set(2, 0.5);
        text_alpha.set(0, 0.5);
        text_show.loadFont("Arial.ttf", ofGetWidth()/10);
        
    }

};



#endif
