#include "testApp.h"

//LOWER LEFT
//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetWindowPosition(ofGetScreenWidth()/2-500,ofGetScreenHeight()/2);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    ballPos = ofPoint(-30,-30);
    
    hasBall = false;
    
    mSenderToAbove.setup("localhost", 70021); //lower left to upper left
    mSenderToRight.setup("localhost", 70022); //lower left to lower right

    mReceiverFromAbove.setup(70002); // upper left
    mReceiverFromRight.setup(70032); // lower right
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    if((hasBall && ballPos.x>ofGetWindowWidth() )){
        ofxOscMessage m;
        m.setAddress("/ball/data/to/right");
        m.addFloatArg(0);
        m.addFloatArg(ballPos.y);
        m.addFloatArg(ballVel.x);
        m.addFloatArg(ballVel.y);
        mSenderToRight.sendMessage(m);
        hasBall = false;
    }
    
    if((hasBall && ballPos.y<0)){
        ofxOscMessage m;
        m.setAddress("/ball/data/to/above");
        m.addFloatArg(ballPos.x);
        m.addFloatArg(ofGetWindowHeight());
        m.addFloatArg(ballVel.x);
        m.addFloatArg(ballVel.y);
        mSenderToAbove.sendMessage(m);
        hasBall = false;
    }
    
    if(hasBall && ballPos.x<0){
        ballVel.x *=-1;
    }
    if(hasBall && ballPos.y>ofGetWindowHeight()){
        ballVel.y *=-1;
    }
    
    ballPos += ballVel;
    
    checkOsc();
    

}

//--------------------------------------------------------------
void testApp::checkOsc(){
    while(mReceiverFromAbove.hasWaitingMessages()){
        cout << "test" << endl;
        ofxOscMessage m;
        mReceiverFromAbove.getNextMessage(&m);
        string addr = m.getAddress();
        
        if(addr == "/ball/data/to/below" ){
            hasBall = true;
            ballPos.x = m.getArgAsFloat(0);
            ballPos.y = m.getArgAsFloat(1);
            ballVel.x = m.getArgAsFloat(2);
            ballVel.y = m.getArgAsFloat(3);
        }
    }
    
    while(mReceiverFromRight.hasWaitingMessages()){
        ofxOscMessage m;
        mReceiverFromRight.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if(addr == "/ball/data/to/left" ){
            hasBall = true;
            ballPos.x = m.getArgAsFloat(0);
            ballPos.y = m.getArgAsFloat(1);
            ballVel.x = m.getArgAsFloat(2);
            ballVel.y = m.getArgAsFloat(3);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    if(hasBall) ofEllipse(ballPos,20,20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
