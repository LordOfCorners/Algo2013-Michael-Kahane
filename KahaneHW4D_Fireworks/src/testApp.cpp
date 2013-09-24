#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();

    ofSetFrameRate(60);
    
    launcher.setup();
}

//--------------------------------------------------------------
void testApp::update(){
    
    // This is how you loop through and delete a particle using iterators and vectors
    // Note how we don't put it++ up in the top of the loop.
    for( vector<Particle>::iterator it=pList.begin(); it!=pList.end(); ){
        it->update();
        
        if( it->bIsDead ){
            it = pList.erase(it);   // When we erase one, it returns the next particle automatically.  It's done the "it++" for us!
            ofLog( OF_LOG_NOTICE, "size is " + ofToString(pList.size()) );
        }else {
            it++;
        }
    }
    launcher.update();
    if(launcher.pos.y<launcher.explodeHeight && !launcher.dead){
        launcher.dead=true;
        
        for( vector<Particle>::iterator it=pList.begin(); it!=pList.end(); ){
            
            it = pList.erase(it);   // When we erase one, it returns the next particle automatically.  It's done the "it++" for us!
                ofLog( OF_LOG_NOTICE, "size is " + ofToString(pList.size()) );
        
        }
        
        for( int i=0; i<50; i++ ){
            addParticle(launcher.pos);
        }
        launcher.setup();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    //trails
    ofColor semiTransparent(20,20,20,255*.30);
    ofSetColor(semiTransparent);
    ofRect(0,0,ofGetWindowWidth(),ofGetWindowHeight());

    for( vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++){
        ofSetColor(launcher.color);
        it->draw();
    }
    launcher.draw();
}

void testApp::addParticle(ofPoint _launcherPos){
    Particle p;
    ofPoint launcherPos = _launcherPos;
    
    // we'll pick a random direction for our particle to move initially
    ofVec2f rVel = ofVec2f( ofRandom(1.0), ofRandom(1.0) ) * 10.0 - 5.0;
    p.setup( rVel, launcherPos );
    pList.push_back( p );
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
