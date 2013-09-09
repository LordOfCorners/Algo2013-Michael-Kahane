#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    for(int i=0; i<ballNum; i++){
        Ball myBall;
        ballList.push_back(myBall);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    for(int i=0; i<ballList.size(); i++){
        ballList[i].update();
        ballList[i].yVelocity+=0.005;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor semiTransparent(20,20,20,255*.40);
    ofSetColor(semiTransparent);
    ofRect(ofGetWindowWidth()/2,ofGetWindowHeight()/2,ofGetWindowWidth(),ofGetWindowHeight());

    for(int i=0; i<ballList.size(); i++){
        ballList[i].draw();
    }
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
