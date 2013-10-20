#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSeedRandom();
    for (int i = 0; i<5; i++){
    Particle car;
        car.pos = ofVec2f(ofRandomWidth(), ofRandomHeight());
        car.dest = ofVec2f( ofRandomWidth(), ofRandomHeight() );
        car.setParams( car.pos, ofVec2f(ofRandom(-10,10), ofRandom(-10,10)) );
        car.carColor = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
        carList.push_back(car);
    }
    
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<carList.size(); i++){
        carList[i].seek( carList[i].dest );
        carList[i].update();
        
        if( carList[i].pos.distance(carList[i].dest) < 5){
            carList[i].dest = ofVec2f( ofRandomWidth(), ofRandomHeight() );
        }
    }
    
    for(int i=0; i<carList.size(); i++){
        for(int j=0; j<carList.size(); j++){
            if(i != j){
                carList[i].avoidCrash(carList[j]);
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<carList.size(); i++){
        ofSetColor(carList[i].carColor);
        carList[i].draw();
        ofCircle( carList[i].dest, 4 );
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
