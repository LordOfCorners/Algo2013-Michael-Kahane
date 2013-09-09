#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    posA = ofPoint(ofGetWindowWidth()/2,ofGetWindowHeight()/4);
    posB = ofPoint(ofGetWindowWidth()/2,ofGetWindowHeight()-ofGetWindowHeight()/4);
    posC = ofPoint(ofGetWindowWidth()/4,ofGetWindowHeight()/2);
    posD = ofPoint(ofGetWindowWidth()-ofGetWindowWidth()/4,ofGetWindowHeight()/2);
    posE = (posA + posC)/2;
    posF = (posB + posD)/2;
    posG = (posB + posC)/2;
    posH = (posA + posD)/2;

}

//--------------------------------------------------------------
void testApp::update(){
    size++;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(72,209,204,100);
    ofCircle(posA,size);
    
    ofSetColor(25,25,112,100);
    ofCircle(posB,size);
    
    ofSetColor(250,128,114,100);
    ofCircle(posC,size);
    
    ofSetColor(255,250,210,100);
    ofCircle(posD,size);
    
    ofSetColor(132,112,255,100);
    ofCircle(posE,size);
    
    ofSetColor(219,112,147,100);
    ofCircle(posF,size);
    
    ofSetColor(72,61,139,100);
    ofCircle(posG,size);
    
    ofSetColor(0,206,209,100);
    ofCircle(posH,size);

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
