//////////////////////////////////
///                            ///
///   ipad remote for PATMAP   ///
///                            ///
//////////////////////////////////

#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"
#include "ofxTweenzor.h"
#include "game_board.h"
#include "me_panel.h"
#include "me_time.h"

//modiffffff


class testApp : public ofxiPhoneApp {
	
public:
	void setup();
	void update();
	void draw();
	void exit();
    
	void touchDown(int x, int y, int id);
	void touchMoved(int x, int y, int id);
	void touchUp(int x, int y, int id);
	void touchDoubleTap(int x, int y, int id);
	void touchCancelled(ofTouchEventArgs &touch);
	
	void lostFocus();
	void gotFocus();
	void gotMemoryWarning();
	void deviceOrientationChanged(int newOrientation);
	void gotMessage(ofMessage msg);
	
    void start(float);
    game_board big_board;
    float fps;
    ofStyle fill;
    me_panel message_dh;
    me_timer message_timeleft;
    me_panel message_lvl;
    me_panel message_lives;
    me_panel message_gameover;
    int touch_dest;
};
