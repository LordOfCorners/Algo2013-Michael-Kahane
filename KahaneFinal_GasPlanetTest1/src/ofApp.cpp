#include "ofApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    
    width = 600;
    height = 600;

    // Initial Allocation
    //
    fluid.allocate(width, height, 0.5);
    fluid2.allocate(width, height, 0.5);
    fluid3.allocate(width, height, 0.5);
    fluid4.allocate(width, height, 0.5);
    fluid5.allocate(width, height, 0.5);
    fluid6.allocate(width, height, 0.5);
    fluid7.allocate(width, height, 0.5);
    fluid8.allocate(width, height, 0.5);

    
    // Seting the gravity set up & injecting the background image
    //
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;
    fluid.setGravity(ofVec2f(0.0,0.0));
//    fluid.setGravity(ofVec2f(0.0,0.0098));
    
    
    fluid2.dissipation = 0.99;
    fluid2.velocityDissipation = 0.99;
    fluid2.setGravity(ofVec2f(0.0,0.0));
//    fluid2.setGravity(ofVec2f(0.0,0.0098));
    
    fluid3.dissipation = 0.99;
    fluid3.velocityDissipation = 0.99;
    fluid3.setGravity(ofVec2f(0.0,0.0));
    //    fluid3.setGravity(ofVec2f(0.0,0.0098));
    
    fluid4.dissipation = 0.99;
    fluid4.velocityDissipation = 0.99;
    fluid4.setGravity(ofVec2f(0.0,0.0));
    //    fluid4.setGravity(ofVec2f(0.0,0.0098));
    
    fluid5.dissipation = 0.99;
    fluid5.velocityDissipation = 0.99;
    fluid5.setGravity(ofVec2f(0.0,0.0));
    //    fluid5.setGravity(ofVec2f(0.0,0.0098));
    
    fluid6.dissipation = 0.99;
    fluid6.velocityDissipation = 0.99;
    fluid6.setGravity(ofVec2f(0.0,0.0));
    //    fluid6.setGravity(ofVec2f(0.0,0.0098));
    
    fluid7.dissipation = 0.99;
    fluid7.velocityDissipation = 0.99;
    fluid7.setGravity(ofVec2f(0.0,0.0));
    //    fluid7.setGravity(ofVec2f(0.0,0.0098));
    
    fluid8.dissipation = 0.99;
    fluid8.velocityDissipation = 0.99;
    fluid8.setGravity(ofVec2f(0.0,0.0));
    //    fluid8.setGravity(ofVec2f(0.0,0.0098));
    
    //  Set obstacle
    //
    fluid.begin();
    ofSetColor(255);
    ofNoFill();
    ofCircle(width*0.5, height*0.5, 200);
    fluid.end();
    
    fluid2.begin();
    ofSetColor(255);
    ofNoFill();
    ofCircle(width*0.5, height*0.5, 200);
    fluid2.end();
    
    fluid3.begin();
    ofSetColor(255);
    ofNoFill();
    ofCircle(width*0.5, height*0.5, 200);
    fluid3.end();
    
    fluid4.begin();
    ofSetColor(255);
    ofNoFill();
    ofCircle(width*0.5, height*0.5, 200);
    fluid4.end();
    
    fluid5.begin();
    ofSetColor(255);
    ofNoFill();
    ofCircle(width*0.5, height*0.5, 200);
    fluid5.end();
    
    fluid6.begin();
    ofSetColor(255);
    ofNoFill();
    ofCircle(width*0.5, height*0.5, 200);
    fluid6.end();
    
    fluid7.begin();
    ofSetColor(255);
    ofNoFill();
    ofCircle(width*0.5, height*0.5, 200);
    fluid7.end();
    
    fluid8.begin();
    ofSetColor(255);
    ofNoFill();
    ofCircle(width*0.5, height*0.5, 200);
    fluid8.end();
    // Adding constant forces
    //
    fluid.addConstantForce(ofPoint(width*0.5,height*0.5), ofPoint(0,-2), ofFloatColor(0.5,0.1,0.0), 10.f);
    fluid2.addConstantForce(ofPoint(width*0.5,height*0.5), ofPoint(0,2), ofFloatColor(0.5,0.1,0.0), 10.f);
    fluid3.addConstantForce(ofPoint(width*0.5,height*0.5), ofPoint(2,0), ofFloatColor(0.5,0.1,0.0), 10.f);
    fluid4.addConstantForce(ofPoint(width*0.5,height*0.5), ofPoint(-2,0), ofFloatColor(0.5,0.1,0.0), 10.f);
    fluid5.addConstantForce(ofPoint(width*0.5,height*0.5), ofPoint(2,2), ofFloatColor(0.5,0.1,0.0), 10.f);
    fluid6.addConstantForce(ofPoint(width*0.5,height*0.5), ofPoint(-2,2), ofFloatColor(0.5,0.1,0.0), 10.f);
    fluid7.addConstantForce(ofPoint(width*0.5,height*0.5), ofPoint(-2,-2), ofFloatColor(0.5,0.1,0.0), 10.f);
    fluid8.addConstantForce(ofPoint(width*0.5,height*0.5), ofPoint(2,-2), ofFloatColor(0.5,0.1,0.0), 10.f);

    ofSetWindowShape(width, height);
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Adding temporal Force
    //
    ofPoint m = ofPoint(mouseX,mouseY);
    ofPoint d = (m - oldM)*10.0;
    oldM = m;
    ofPoint c = ofPoint(640*0.5, 480*0.5) - m;
    c.normalize();
//    fluid.addTemporalForce(m, d, ofFloatColor(c.x,c.y,0.5)*sin(ofGetElapsedTimef()),3.0f);
    //  Update
    //
    fluid.update();
    fluid2.update();
    fluid3.update();
    fluid4.update();
    fluid5.update();
    fluid6.update();
    fluid7.update();
    fluid8.update();

    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    
    fluid.draw();
    fluid2.draw();
    fluid3.draw();
    fluid4.draw();
    fluid5.draw();
    fluid6.draw();
    fluid7.draw();
    fluid8.draw();

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