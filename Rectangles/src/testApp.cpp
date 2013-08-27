#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    
    myRect.pos.x= ofGetWindowWidth()/2;
    myRect.pos.y= ofGetWindowHeight()/2;
    
    //starting point
    myRect.posA.x = 10;
    myRect.posA.y = 100;
    
    //ending point
    myRect.posB.x = 500;
    myRect.posB.y = 540;
    
    myRect.interpolateByPct(0.0f);
    
    pct = 0;
}

//--------------------------------------------------------------
void testApp::update(){
//    pct += 0.001f;
//    if(pct>1){
//        pct=0;
//    }
// 
//    myRect.interpolateByPct(pct);
    myRect.xenoToPoint(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::draw(){
    myRect.draw();
    
    ofSetColor(0);
    ofDrawBitmapString(ofToString(pct), ofPoint(10,10));
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
//    pct = (float)y / (float)ofGetWindowHeight();
//    
//    myRect.interpolateByPct(pct);
    
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
