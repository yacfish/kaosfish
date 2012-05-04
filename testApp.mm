#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
    
	ofBackground(225, 225, 225, 20);
	ofSetCircleResolution(80);
	
	ofxRegisterMultitouch(this);
	
	ofxAccelerometer.setup();

	ofxiPhoneAlerts.addListener(this);
	
    Tweenzor::init();
    fps = 0;
    big_board.init();
    
}


//--------------------------------------------------------------
void testApp::update() {
    
    	
    Tweenzor::update();
    fps = ( fps * 0.95 ) + ( ofGetFrameRate() * 0.05 );
    big_board.update();    
	
}

//--------------------------------------------------------------
void testApp::draw() {
	ofSetColor(54);
	ofDrawBitmapString("death hold", 10, 20);
    ofDrawBitmapString("fps: " + ofToString(fps, 2) , 10, 50);
    
	ofEnableAlphaBlending();
	//ofSetColor(255);
	
    big_board.draw();
    
}

//--------------------------------------------------------------
void testApp::exit() {
    
}

//--------------------------------------------------------------
void testApp::touchDown(int x, int y, int id){
    
	if (id == 0) {
        
        big_board.touchdown1(x,y,fps);
        
    }
    
}

//--------------------------------------------------------------
void testApp::touchMoved(int x, int y, int id){
	
	if (id == 0) {
        
        big_board.touchmoved1(x,y,fps);
        
    }
}

//--------------------------------------------------------------
void testApp::touchUp(int x, int y, int id){
    
    if (id == 0) {
        
        big_board.touchup1(x,y,fps);
        
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
