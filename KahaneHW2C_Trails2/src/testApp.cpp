#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    posA.x = (ofGetWindowWidth()/4)/2;
    posA.y = ofGetWindowHeight()-(ofGetWindowWidth()/4)/2;
    posB.x = ofGetWindowWidth()-(ofGetWindowWidth()/4)/2;
    posB.y = (ofGetWindowHeight()/4)/2;
    posC.x = (ofGetWindowWidth()/4)/2;
    posC.y = (ofGetWindowHeight()/4)/2;
    posD.x = ofGetWindowWidth()-(ofGetWindowWidth()/4)/2;
    posD.y = ofGetWindowHeight()-(ofGetWindowHeight()/4)/2;


}

//--------------------------------------------------------------
void testApp::update(){
    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofColor semiTransparent(20,20,20,255*.10);
//    ofSetColor(semiTransparent);
//    ofRect(ofGetWindowWidth()/2,ofGetWindowHeight()/2,ofGetWindowWidth(),ofGetWindowHeight());
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(100,255,0,150);
    ofRect(posA,ofGetWindowWidth()/4,ofGetWindowHeight()/4);
    posA.x++;
    posA.y--;
    
    ofSetColor(255,100,0,150);
    ofRect(posB,ofGetWindowWidth()/4,ofGetWindowHeight()/4);
    posB.x--;
    posB.y++;
    
    ofSetColor(0,100,255,150);
    ofRect(posC,ofGetWindowWidth()/4,ofGetWindowHeight()/4);
    posC.x++;
    posC.y++;
    
    ofSetColor(250,250,210,150);
    ofRect(posD,ofGetWindowWidth()/4,ofGetWindowHeight()/4);
    posD.x--;
    posD.y--;
    

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
