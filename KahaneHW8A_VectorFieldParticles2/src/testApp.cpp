#include "testApp.h"
#include "ofxXmlSettings.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 10 );
    particleList.clear();
    vid.initGrabber(ofGetWindowWidth(),ofGetWindowHeight(),true);

    ofBackground(0);
    
    //add particles
    for( int i=0; i<30000; i++ ){ //play with this number
        addParticle();
    }
    
}

//--------------------------------------------------------------
void testApp::addParticle() {
    Particle part;
    part.pos = ofVec2f( ofRandom(-300,ofGetWindowWidth()+300), ofRandom(-300,ofGetWindowHeight()+300) );
    particleList.push_back( part );
}

//--------------------------------------------------------------
void testApp::update(){
    myField.update(vid);
    vid.update();

    //add forces
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].applyForce( myField.getForceAtPosition(particleList[i].pos ) * 0.004 );
        particleList[i].update();
    }
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
 }

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(20,20,20,255*.4);
    ofRect(0,0,ofGetWindowWidth(),ofGetWindowHeight());
    ofSetColor(255,255,255,255*.02);
//    myField.draw();

    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].draw();
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
