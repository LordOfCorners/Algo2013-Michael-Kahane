#include "testApp.h"



/**
 *  This app is set up to receive a 'bangs' track from Duration.  It simply makes a flash of light when it gets a signal.
 *
 */

//--------------------------------------------------------------
void testApp::setup(){
    mReceiver.setup(12345);
    
    bgColor = 0;
    ofBackground(0);
    
    for(int i=0; i<7;i++){
        Tornado newTornado;
        newTornado.setup(i+10);
        tornadoList.push_back(newTornado);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    
    
    bgColor *= 0.95;
    
    for(int i=0; i<tornadoList.size();i++){
        tornadoList[i].update();
    }
    cout << volume << endl;
    
}

void testApp::checkOsc() {
    
	while(mReceiver.hasWaitingMessages()){
        
		ofxOscMessage m;
		mReceiver.getNextMessage(&m);
        string addr = m.getAddress();
        
//        cout << "got a message " << addr << endl;
        
        if( addr == "/colors" ){
            color = ofColor(m.getArgAsInt32(0),m.getArgAsInt32(1),m.getArgAsInt32(2));
        }
        
        if( addr == "/audio" ){
            volume = ofMap(m.getArgAsFloat(15),0.0,0.5,1,30);
        }
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    cam.begin();
    cam.setDistance(80);
    cam.roll(3);
    cam.rotate(90, 0, 0, 1);
    for(int i=0; i<tornadoList.size();i++){
        ofSetLineWidth(volume);
        ofSetColor(color);

        tornadoList[i].draw(volume);
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
