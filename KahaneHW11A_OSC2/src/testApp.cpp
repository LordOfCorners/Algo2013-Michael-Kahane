#include "testApp.h"

//UPPER RIGHT
//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetWindowPosition(ofGetScreenWidth()/2,ofGetScreenHeight()/2-400);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    ballPos = ofPoint(-30,-30);
    
    hasBall = false;
    
    mSenderToLeft.setup("localhost", 70011); //upper right to upper left
    mSenderToBelow.setup("localhost", 70012); //upper right to lower right

    
    mReceiverFromLeft.setup(70001); // upper left
    mReceiverFromBelow.setup(70031); // lower right
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    if((hasBall && ballPos.x<0 )){
        ofxOscMessage m;
        m.setAddress("/ball/data/to/left");
        m.addFloatArg(ofGetWindowWidth());
        m.addFloatArg(ballPos.y);
        m.addFloatArg(ballVel.x);
        m.addFloatArg(ballVel.y);
        mSenderToLeft.sendMessage(m);
        hasBall = false;
    }
    
    if((hasBall && ballPos.y>ofGetWindowHeight())){
        ofxOscMessage m;
        m.setAddress("/ball/data/to/below");
        m.addFloatArg(ballPos.x);
        m.addFloatArg(0);
        m.addFloatArg(ballVel.x);
        m.addFloatArg(ballVel.y);
        mSenderToBelow.sendMessage(m);
        hasBall = false;
    }
    
    if(hasBall && ballPos.x>ofGetWindowWidth()){
        ballVel.x *=-1;
    }
    if(hasBall && ballPos.y<0){
        ballVel.y *=-1;
    }
    
    ballPos += ballVel;
    
    checkOsc();
    

}

//--------------------------------------------------------------
void testApp::checkOsc(){
    while(mReceiverFromBelow.hasWaitingMessages()){
        ofxOscMessage m;
        mReceiverFromBelow.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if(addr == "/ball/data/to/above" ){
            hasBall = true;
            ballPos.x = m.getArgAsFloat(0);
            ballPos.y = m.getArgAsFloat(1);
            ballVel.x = m.getArgAsFloat(2);
            ballVel.y = m.getArgAsFloat(3);
        }
    }
    
    while(mReceiverFromLeft.hasWaitingMessages()){
        cout << "test" << endl;

        ofxOscMessage m;
        mReceiverFromLeft.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if(addr == "/ball/data/to/right" ){
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
