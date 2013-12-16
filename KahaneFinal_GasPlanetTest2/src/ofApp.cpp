#include "ofApp.h"

//--------------------------------------------------------------
void testApp::setup(){
//    ofEnableAlphaBlending();
//    ofSetCircleResolution(100);
    ofBackground(0);
//    ofSetBackgroundAuto(false);
    
    width = 200;
    height = 200;

    // Initial Allocation
    //
    fluid.allocate(width, height, 0.5);

    
    // Seting the gravity set up & injecting the background image
    //
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;
    fluid.setGravity(ofVec2f(0.0,0.0));
//    fluid.setGravity(ofVec2f(0.0,0.0098));
    
    //  Set obstacle
    //
    fluid.begin();
    ofSetColor(200);
    ofNoFill();
    ofCircle(width*0.5, height*0.5, 100);
    fluid.end();

    // Adding constant forces
    //
    fluid.addConstantForce(ofPoint(width*0.5,height*0.5), ofPoint(0,-2), ofFloatColor(0.5,0.05,0.0), 15.f, 0.f, 1.f);
    fluid.addConstantForce(ofPoint(width*0.75,height*0.5), ofPoint(-2,0), ofFloatColor(0.5,0.05,0.0), 15.f, 0.f, 1.f);
    fluid.addConstantForce(ofPoint(width*0.25,height*0.25), ofPoint(-2,-6), ofFloatColor(0.5,0.05,0.0), 15.f, 0.f, 1.f);


//    ofSetWindowShape(width, height);
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Adding temporal Force
    //
//    ofPoint m = ofPoint(mouseX,mouseY);
//    ofPoint d = (m - oldM)*10.0;
//    oldM = m;
//    ofPoint c = ofPoint(640*0.5, 480*0.5) - m;
//    c.normalize();
//    fluid.addTemporalForce(m, d, ofFloatColor(c.x,c.y,0.5)*sin(ofGetElapsedTimef()),3.0f);
    
    float radius = sin(ofGetElapsedTimef())*20+50;
    float angle = ofGetElapsedTimef();

    float x = radius*cos(angle);
    float y = radius*sin(angle);
    oldM = ofVec2f(x,y);
    ofPoint m = ofPoint(x+width/2,y+width/2);
    ofPoint d = (m-oldM)*10.0;
    ofPoint c = ofPoint(640*0.5, 480*0.5) - m;
    fluid.addTemporalForce(m, d, ofFloatColor(c.x,c.y,0.5),0.40f);
    
    //  Update
    //
    fluid.update();

    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::draw(){
//    ofTranslate(ofGetWindowWidth()/4,ofGetWindowHeight()/4);
//    ofPushMatrix();
//    ofScale(4,4,4);
    fluid.draw();
//    float radius = 80;
//    float angle = ofGetElapsedTimef();
//    
//    float x = radius*cos(angle);
//    float y = radius*sin(angle);
//    ofSetColor(255);
//    ofFill();
//    ofCircle(x+width/2,y+width/2,5);
//    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if( key == 'p')
        bPaint = !bPaint;
    if( key == 'o')
        bObstacle = !bObstacle;
    if( key == 'b')
        bBounding = !bBounding;
    if( key == 'c')
        bClear = !bClear;
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