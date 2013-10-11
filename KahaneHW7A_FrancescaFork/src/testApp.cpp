// inspired by Francesca Castelli who was insipired Gustavo Faria
//https://github.com/fracast/castelli_algo2013

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    pos = ofGetWindowSize()/2;
    ofSetVerticalSync(true);
    
    ofSetBackgroundAuto(true); //set to false for a more drawy thing that was closer to what francesca had.
    ofEnableAlphaBlending();
    ofBackground(0);
    

    

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    float angle = ofGetElapsedTimef()   * 0.5;
    float radius = 700;
    
    float x = radius * cos(angle * 1);
    float y = radius * sin( angle * 1);
    float z = radius * cos(angle * 1);

    
    ofPoint temp;
    temp.x = x;
    temp.y = y;
    temp.z = z;

    pointList.push_back(temp);
    if( pointList.size() > 20 ){
        pointList.erase( pointList.begin());
    }
    
    //LETS MAKE THIS THREE DIMENSIONAL!!!!!
    cam.begin();
    cam.getTarget().setPosition(x,y,z);
//    cam.setAutoDistance(true);
    for (int i=0; i<pointList.size(); i++) {
        ofPushMatrix();{
            ofSetLineWidth(5);
            ofSetRectMode(OF_RECTMODE_CENTER);
//            ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
            ofRotateZ(ofGetElapsedTimef() * 2.0*i);
            ofNoFill();
            ofSetColor(0,255 * 0.06 * i, 255,30);
            ofDrawCone(x,y,z*1.3,i*30,i*30);
//            ofTriangle(x,y,30*i,30*i, 30* i, 30*i);
            
        }ofPopMatrix();
    }
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
