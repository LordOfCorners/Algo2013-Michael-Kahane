#include "testApp.h"
//Worked with Anthony Marefat (SafetyOrange on GitHub)
//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    //gravity of planet(m/s) times 2.794 and divide by 60
    
    earth.setup(0.456,0.85,ofColor(55,34,240), ofVec2f(ofRandom(0.0,1.0),ofRandom(0.0,1.0)),ofVec2f(ofRandom(ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()/4)),50);
    jupiter.setup(1.154,0.85,ofColor(244,164,96), ofVec2f(ofRandom(0.0,1.0),ofRandom(0.0,1.0)),ofVec2f(ofRandom(ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()/4)),100);
    moon.setup(0.07553113333,0.85,ofColor(150,150,150), ofVec2f(ofRandom(0.0,1.0),ofRandom(0.0,1.0)),ofVec2f(ofRandom(ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()/4)),10);


}

//--------------------------------------------------------------
void testApp::update(){
    earth.update();
    jupiter.update();
    moon.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    earth.draw();
    jupiter.draw();
    moon.draw();
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
    if(ofDist(earth.pos.x,earth.pos.y,x,y)<earth.r){
        earth.vel.x = ofRandom(-20,20);
        earth.vel.y = ofRandom(-20,20);
    }
    if(ofDist(jupiter.pos.x,jupiter.pos.y,x,y)<jupiter.r){
        jupiter.vel.x = ofRandom(-20,20);
        jupiter.vel.y = ofRandom(-20,20);
    }
    if(ofDist(moon.pos.x,moon.pos.y,x,y)<moon.r){
        moon.vel.x = ofRandom(-20,20);
        moon.vel.y = ofRandom(-20,20);
    }
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
