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


#include "board.h"

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
	
    board big_board;
	ofImage arrow;
    float fps;
    
    
};
