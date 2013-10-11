#include "testApp.h"
#include "ofxXmlSettings.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofxXmlSettings settings;
    settings.loadFile("settings.xml");
    settingSelection = settings.getValue("settings:selection", 0.0);
    
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    
    ofBackground(10,200,70);
    
    if(settingSelection==1){
        myField.setRandom();
    }else if( settingSelection==2 ){
        myField.setPerlin();
    }else if( settingSelection==3 ){
        myField.sinYsinX();
    }else if( settingSelection==4 ){
        myField.negYposX();
    }else if( settingSelection==5 ){
        myField.sinXcosY();
    }
}

//--------------------------------------------------------------
void testApp::exit(){
    ofxXmlSettings settings;
    settings.setValue("settings:selection", settingSelection);
    settings.saveFile("settings.xml");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    myField.draw();
    if(settingSelection!=1) {
        ofDrawBitmapString("Press 1 for random",800,20);
    }else{
        ofDrawBitmapStringHighlight("Press 1 for random",800,20);
    }
    
    if(settingSelection!=2) {
        ofDrawBitmapString("Press 2 for Perlin Noise",800,40);
    }else{
        ofDrawBitmapStringHighlight("Press 2 for Perlin Noise",800,40);
    }
    
    if(settingSelection!=3) {
        ofDrawBitmapString("Press 3 for Sin(y),Sin(x)",800,60);
    }else{
        ofDrawBitmapStringHighlight("Press 3 for Sin(y),Sin(x)",800,60);
    }
    
    if(settingSelection!=4) {
        ofDrawBitmapString("Press 4 for -y,x",800,80);
    }else{
        ofDrawBitmapStringHighlight("Press 4 for -y,x",800,80);
    }
    
    if(settingSelection!=5) {
        ofDrawBitmapString("Press 5 for Sin(x),Cos(y)",800,100);
    }else{
        ofDrawBitmapStringHighlight("Press 5 for Sin(x),Cos(y)",800,100);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if( key == '1'){
        settingSelection=1;
        myField.setRandom();

    }else if( key == '2' ){
        settingSelection=2;
        myField.setPerlin();

    }else if( key == '3' ){
        settingSelection=3;
        myField.sinYsinX();

    }else if( key == '4' ){
        settingSelection=4;
        myField.negYposX();

    }else if( key == '5' ){
        settingSelection=5;
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
