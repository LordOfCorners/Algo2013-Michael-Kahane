#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    video.loadMovie("pingpong.mp4");
//    video.loadMovie("open.mp4");
//    video.loadMovie("faucet.mp4");
    video.setLoopState(OF_LOOP_NORMAL);
    //video.setSpeed(0.4);
    video.play();
}

//--------------------------------------------------------------
void testApp::update(){
    
    video.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,180);
    video.draw(0,0);
    
    ofSetLineWidth(3);
    ofSetColor(255,0,0);
    TS.draw(video.getPosition());
    for (int i = 0; i < strokes.size(); i++){
        strokes[i].draw(video.getPosition());
    }
    ofDrawBitmapStringHighlight("1)Ping Pong, 2) Open Sign, 3) Facuet", ofPoint(video.getWidth() + 50, 20), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("press ' ' to clear", ofPoint(video.getWidth() + 50, 50), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("press a to reset video position", ofPoint(video.getWidth() + 50, 80), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("press + to increase video speed", ofPoint(video.getWidth() + 50, 110), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("press - to increase video speed", ofPoint(video.getWidth() + 50, 140), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("video speed: " + ofToString(video.getSpeed(), 3), ofPoint(video.getWidth() + 50, 170), ofColor::magenta, ofColor::white);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == ' '){
        strokes.clear();
        TS.pts.clear();
    }
    
    if (key == 'a'){
        video.setPosition(0);
    }
    
    if (key == '+'){
        video.setSpeed(video.getSpeed()+0.05);
    }
    
    if (key == '-'){
        video.setSpeed(video.getSpeed()-0.05);
    }
    
    if (key == '1'){
        video.loadMovie("pingpong.mp4");
    }
    if (key == '2'){
        video.loadMovie("open.mp4");
    }
    if (key == '3'){
        video.loadMovie("faucet.mp4");
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    TS.addPoint(video.getPosition(),ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    strokes.push_back(TS);
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