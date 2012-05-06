#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
    
	ofBackground(255,255,255, 20);
	ofSetCircleResolution(80);
	ofxRegisterMultitouch(this);
	ofxAccelerometer.setup();
	ofxiPhoneAlerts.addListener(this);
    
    Tweenzor::init();
    
    fps = 0;
    
    big_board.init();
    
    
    
    fill.bFill = false;
    message_dh.init();
    message_lvl.init();
    message_dh.show("DEATH HOLD", ofGetWidth()/2, ofGetHeight()/2,ofGetWidth()*0.95, ofGetHeight()/10);
    touch_dest = 1;
       
}


//--------------------------------------------------------------
void testApp::update() {
    
    Tweenzor::update();	
    
    
    //fps = ( fps * 0.95 ) + ( ofGetFrameRate() * 0.05 );
    
    fps = ofGetFrameRate();
    big_board.update();
    if (big_board.show_level) {
        
        big_board.show_level = false;
        message_lvl.show("LEVEL "+ofToString(big_board.level), ofGetWidth()/2, ofGetHeight()/2,ofGetWidth()*0.95, ofGetHeight()/10);

    }
 
	
}

//--------------------------------------------------------------
void testApp::draw() {
	
	ofEnableAlphaBlending();
	
    big_board.draw(fill);
    message_dh.draw();
    message_lvl.draw();
    ofDisableAlphaBlending();
    
}

//--------------------------------------------------------------
void testApp::exit() {
    
}

//--------------------------------------------------------------
void testApp::touchDown(int x, int y, int id){
    
	if (id == 0) {
        switch (touch_dest) {
            case 1:
                touch_dest = 2;
                message_dh.kill();
                message_lvl.auto_kill = true;
                message_lvl.show("LEVEL "+ofToString(big_board.level), ofGetWidth()/2, ofGetHeight()/2,ofGetWidth()*0.95, ofGetHeight()/10, 0.5);
                break;
            case 2:
                big_board.touchdown1(x,y);
                break;
        }
    }
    
}

//--------------------------------------------------------------
void testApp::touchMoved(int x, int y, int id){
	
	if (id == 0) {
        switch (touch_dest) {
            case 1:
                //  message.touchup1(x,y);
                break;
            case 2:
                big_board.touchmoved1(x,y);
                break;
        }
    }
}

//--------------------------------------------------------------
void testApp::touchUp(int x, int y, int id){
    
    if (id == 0) {
        switch (touch_dest) {
            case 1:
              //  message.touchup1(x,y,fps);
                
                break;
            case 2:
                big_board.touchup1(x,y);
                break;
                
        } 
                
    }
    
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(int x, int y, int id){
	printf("touch %i double tap at (%i,%i)\n", id, x, y);
}

//--------------------------------------------------------------
void testApp::lostFocus() {
}

//--------------------------------------------------------------
void testApp::gotFocus() {
}

//--------------------------------------------------------------
void testApp::gotMemoryWarning() {
}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){
}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs& args){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

;
