#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofEnableAlphaBlending();
    
    // Setup post-processing chain
    post.init(ofGetWidth(), ofGetHeight());
    post.createPass<FxaaPass>()->setEnabled(true);
    post.createPass<BloomPass>()->setEnabled(true);
    post.createPass<DofPass>()->setEnabled(true);
    post.createPass<KaleidoscopePass>()->setEnabled(true);
    post.createPass<NoiseWarpPass>()->setEnabled(true);
    post.createPass<PixelatePass>()->setEnabled(false);
    post.createPass<EdgePass>()->setEnabled(false);
    
    
    for(int i=0; i<100;i++){
        Rectangle myRect;
        myRect.setup(ofVec2f(ofRandom(-ofGetWindowWidth(),ofGetWindowWidth()),ofRandom(-ofGetWindowHeight(),ofGetWindowHeight())), ofVec2f(ofRandom(-ofGetWindowWidth(),ofGetWindowWidth()),ofRandom(-ofGetWindowHeight(),ofGetWindowHeight())),ofColor(ofRandom(255),ofRandom(255),ofRandom(255),ofRandom(150,200)),ofRandom(400,900),ofRandom(400,900),ofVec2f(ofRandom(-ofGetWindowWidth(),ofGetWindowWidth()),ofRandom(-ofGetWindowHeight(),ofGetWindowHeight())),ofVec2f(ofRandom(-ofGetWindowWidth(),ofGetWindowWidth()),ofRandom(-ofGetWindowHeight(),ofGetWindowHeight())));
        rectList.push_back(myRect);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i=0; i<rectList.size();i++){
        if(ofGetElapsedTimef()<5){
            rectList[i].interpolateByPct(rectList[i].pos, rectList[i].newPos, .15);
        }
        if(ofGetElapsedTimef()>5 && ofGetElapsedTimef()<10){
            rectList[i].interpolateByPct(rectList[i].pos, rectList[i].newPos2, .15);
        }
        if(ofGetElapsedTimef()>10){
            rectList[i].interpolateByPct(rectList[i].pos, rectList[i].newPos3, .15);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    light.enable();
    post.begin(cam);
//    blueRect.draw();
//    orangeRect.draw();
//    whiteRect.draw();

    for (int i=0; i<rectList.size();i++){
        rectList[i].draw();
    }
    post.end();

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
