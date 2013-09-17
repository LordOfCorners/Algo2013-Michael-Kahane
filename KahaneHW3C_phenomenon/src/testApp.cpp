#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetCircleResolution(100);
//    myTornado.setup();
    
    for(int i=0; i<7;i++){
        Tornado newTornado;
        newTornado.setup(i+10);
        tornadoList.push_back(newTornado);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
//    myTornado.update();
    for(int i=0; i<tornadoList.size();i++){
        tornadoList[i].update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    cam.begin();
//    myTornado.draw();
//    cam.lookAt(myTornado.pos,ofVec3f(0, 1, 0));
//    cam.tilt(5);
    for(int i=0; i<tornadoList.size();i++){
        tornadoList[i].draw();
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
