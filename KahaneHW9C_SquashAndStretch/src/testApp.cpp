#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(255);
    
    for (int i = 0; i < 10; i++){
        addParticle();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    // on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    

	
    for (int i=0; i < particleList.size(); i++){
        particleList[i].resetForces();
//		particleList[i].addForce( ofVec2f(0,0.04));  // gravity
//		particleList[i].addDampingForce();
		particleList[i].update();
	}
    for(int i=0; i < particleList.size(); i++){
        for(int j=0; j < particleList.size(); j++){
//            if(i!=j){
                particleList[i].rotation = getAngleOfImpact(particleList[i], particleList[j]);
                
//            }
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0);
    for (int i=0; i < particleList.size(); i++){
        particleList[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::addParticle() {
    Particle myParticle;
    
    float vx = ofRandom(-4,4);
    float vy = ofRandom(-4,4);
    myParticle.setParams(300,300,vx, vy);
    
    // more interesting with diversity :)
    // uncomment this:
    //		myParticle.damping = ofRandom(0.01, 0.05);
    particleList.push_back(myParticle);
}

float testApp::getAngleOfImpact(Particle part1, Particle part2){
    float angle;
    if (part1.pos.x < 25 || part1.pos.x > ofGetWindowWidth()-25){
        float angle = 0;
        return angle;
    }
    if (part1.pos.y < 25 || part1.pos.y > ofGetWindowHeight()-25) {
        float angle = -90;
        return angle;
    }
    angle =  ofRadToDeg(atan2(part1.vel.y,part1.vel.x))+90;
    return angle;

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
