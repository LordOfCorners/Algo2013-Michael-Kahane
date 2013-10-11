#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofBackground(0);
    
	for (int i = 0; i < 30000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,1000),ofRandom(0,1000),0,0);
		// more interesting with diversity :)
		// uncomment this:
		myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
    
    for(int i=0; i<3;i++){
        addAttractor();
    }
    

}

void testApp::addAttractor(){
    attractor tmpAttractor;
    attractorList.push_back(tmpAttractor);
}

//--------------------------------------------------------------
void testApp::update(){
    // on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
    for(int j = 0; j < attractorList.size(); j++){

	for (int i = 0; i < particles.size(); i++){
            particles[i].resetForce();
            
            
            particles[i].addAttractionForce(attractorList[j].pos.x, attractorList[j].pos.y, 100, 0.1);
            particles[i].addRepulsionForce(attractorList[j].pos.x, attractorList[j].pos.y, 50, 1);

            
            
            //		particles[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 0.1);
            //		particles[i].addClockwiseForce(mouseX, mouseY, 200, 1);
            
            //particles[i].addForce(0,0.04);  // gravity
        particles[i].addDampingForce();
        particles[i].update();

        }
    }
    

    
    for(int i=0; i<attractorList.size();i++){
        attractorList[i].update();
    }

    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor semiTrans = ofColor(20,20,20,255*.1);
    ofSetColor(semiTrans);
    ofRect(0,0,ofGetWindowWidth(),ofGetWindowHeight());
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
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
    for(int i=0; i<attractorList.size();i++){
//        attractorList[i].setParams(x,y);
    }
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
