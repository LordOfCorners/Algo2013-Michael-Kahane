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
    for( int i=0; i<20000; i++ ){ //play with this number
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

    ofLog( OF_LOG_NOTICE, "size is " + ofToString(particleList.size()) );

    for( vector<Particle>::iterator it=particleList.begin(); it!=particleList.end(); ){
        
        if(it->pos.x<-300|| it->pos.x>ofGetWindowWidth()+300 || it->pos.y>ofGetWindowHeight()+300 ){
            it = particleList.erase(it);
            
            Particle part;
            part.pos = ofVec2f( ofRandom(-300,ofGetWindowWidth()+300), ofRandom(-300,ofGetWindowHeight()+300) );
            particleList.push_back( part );
            
        }else {
            it++;
        }
    }
    
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].applyForce( myField.getForceAtPosition(particleList[i].pos ) * 0.004 );
        particleList[i].update();
        
//        unsigned char *pixels=vid.getPixels();
//        int index = particleList[i].pos.y*vid.getWidth()*3 + particleList[i].pos.x*3;
//        int red = pixels[index];
//        int green = pixels[index+1];
//        int blue = pixels[index+2];
//        particleList[i].color = ofColor(red,green,blue);

    }
    
    
    
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    
 }

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
    ofSetColor(20,20,20,255*.2);
//    ofRect(0,0,ofGetWindowWidth(),ofGetWindowHeight());
    ofSetColor(255,255,255,255*.02);
//    myField.draw();

    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].draw();
    }
    ofPopMatrix();
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'r'){
        for(int i = 0; i<particleList.size(); i++){
            particleList[i].reset();
        }
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
