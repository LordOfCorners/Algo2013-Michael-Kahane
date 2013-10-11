#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    myField.draw();
    ofDrawBitmapString("Press 1 for random",800,20);
    ofDrawBitmapString("Press 2 for Perlin Noise",800,35);
    ofDrawBitmapString("Press 3 for Sin(y),Sin(x)",800,50);
    ofDrawBitmapString("Press 4 for -y,x",800,65);
    ofDrawBitmapString("Press 5 for Sin(x),Cos(y)",800,80);


    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if( key == '1'){
        myField.setRandom();
    }else if( key == '2' ){
        myField.setPerlin();
    }else if( key == '3' ){
        myField.sinYsinX();
    }else if( key == '4' ){
        myField.negYposX();
    }else if( key == '5' ){
        myField.sinXcosY();
    }

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
