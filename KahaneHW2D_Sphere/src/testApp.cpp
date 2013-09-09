#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
    
    // this uses depth information for occlusion
	// rather than always drawing things on top of each other
	ofEnableDepthTest();
    mySphere.setup(ofColor(100,200,255),ofVec3f(1,2,2),ofVec3f(0,0,0),32);
}

//--------------------------------------------------------------
void testApp::update(){
    mySphere.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0, 0, 0);
    ofNoFill();
    cam.begin();
    ofSetLineWidth(1);
    mySphere.draw();
    ofSetLineWidth(10);
    ofDrawBox(0,0,0,400);
    
    cam.end();

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
