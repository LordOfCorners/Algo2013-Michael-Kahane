#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    
    //    myParticle.setParams(300,300,ofRandom(-1,1)*10,ofRandom(-1,1)*10);
    
    for(int i=0; i<400;i++){
        addParticle();
    }

}

void testApp::addParticle(){
    Particle tmpParticle;
    float vx = ofRandom(-4,4);
    float vy = ofRandom(-4,4);
    
    tmpParticle.setParams(300, 300, vx, vy);
    
    particleList.push_back(tmpParticle);
}


//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<particleList.size();i++){
        particleList[i].resetForces();
//        particleList[i].addForce(ofVec2f(0,0.1));
        particleList[i].addDampingForce();
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
//    ofColor semiTransparent(20,20,20,255*.30);
//    ofSetColor(semiTransparent);
//    ofRect(0,0,ofGetWindowWidth(),ofGetWindowHeight());
    for(int i=0; i<particleList.size();i++){
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
    for(int i=0; i<particleList.size();i++){
        
        float circVal = ofRandom(TWO_PI);
        float vx = cos(circVal)*ofRandom(0,4);
        float vy = sin(circVal)*ofRandom(0,4);
        
        particleList[i].setParams(x,y,vx,vy);
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
