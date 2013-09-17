#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    
    ofSetCircleResolution(100);
    
    leftEye.pos = ofPoint( ofGetWindowWidth()/2 - 75, ofGetWindowHeight() * 0.5 );
    rightEye.pos = ofPoint( ofGetWindowWidth()/2 + 75, ofGetWindowHeight() * 0.5 );
    facePos = ofPoint(ofGetWindowSize()/2);
    catchUp = 0.03f;

}

//--------------------------------------------------------------
void testApp::update(){
    ofPoint mousePos( mouseX, mouseY );
    
    leftEye.mousePos = mousePos;
    rightEye.mousePos = mousePos;
    facePos.x = catchUp * mouseX + (1-catchUp) * facePos.x;
    facePos.y = catchUp * mouseY + (1-catchUp) * facePos.y;
    
    float sinOfTime = sin( ofGetElapsedTimef() * 2 );
    sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 400, 500);


}

//--------------------------------------------------------------
void testApp::draw(){
    leftEye.draw(ofPoint(-60,0));
    rightEye.draw(ofPoint(60,0));
    
    ofNoFill();
    ofEllipse(facePos.x,facePos.y+50,sinOfTimeMapped,sinOfTimeMapped);
    ofBezier(facePos.x-15,facePos.y+70,facePos.x+5,facePos.y+90, facePos.x+15,facePos.y+90, facePos.x+25,facePos.y+70);
    ofBezier(facePos.x-100,facePos.y+200,facePos.x,facePos.y+250, facePos.x+50,facePos.y+250, facePos.x+100,facePos.y+200);

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
