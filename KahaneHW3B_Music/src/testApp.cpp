#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
	song.loadSound("sounds/brokendate.mp3");
    song.setVolume(1.0f);
    song.play();

    // the fft needs to be smoothed out, so we create an array of floats
	// for that purpose:
	fftSmoothed = new float[8192];
	for (int i = 0; i < 8192; i++){
		fftSmoothed[i] = 0;
	}
	
	nBandsToGet = 1;
    
    counter=200;


}

//--------------------------------------------------------------
void testApp::update(){
    // update the sound playing system:
	ofSoundUpdate();
    
    float * val = ofSoundGetSpectrum(nBandsToGet);		// request 128 values for fft
	for (int i = 0;i < nBandsToGet; i++){
		
		// let the smoothed calue sink to zero:
		fftSmoothed[i] *= 0.96f;
		
		// take the max, either the smoothed or the incoming:
		if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
		
	}

    
    theta = ofMap(counter, 0, ofGetWindowWidth(), 0, PI/2);
    counter+=((fftSmoothed[0]*1000)/2);

}

//--------------------------------------------------------------
void testApp::draw(){

    ofColor semiTransparent(20,20,20,255*.10);
    ofSetColor(semiTransparent);
    ofRect(0,0,ofGetWindowWidth(),ofGetWindowHeight());
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);

//    ofCircle(ofGetWindowSize()/2,fftSmoothed[0]*100);
    branch(200,theta,fftSmoothed[0]);
}
//--------------------------------------------------------------

void testApp::branch(float h, float _theta, float level) {
    //Recursive Branch code comes from daniel shiffman nature of code
    
    // Each branch will be 2/3rds the size of the previous one
    h *= 0.66;
    // All recursive functions must have an exit condition!!!!
    // Here, ours is when the length of the branch is 2 pixels or less
    if (h > 2.3) {
        ofPushMatrix();    // Save the current state of transformation (i.e. where are we now)
        ofRotate(_theta);   // Rotate by theta
        //    fill(random(255),random(255),random(255));
        ofSetColor(64, 191, 239);
        ofEllipse(h, h*level*100, 1, 20);
        //    line(0,0,0,-h);  // Draw the branch
        ofTranslate(0, -1.2*h); // Move to the end of the branch
        branch(h,_theta,level);       // Ok, now call myself to draw two new branches!!
        ofPopMatrix();     // Whenever we get back here, we "pop" in order to restore the previous matrix state
        
        // Repeat the same thing, only branch off to the "left" this time!
        ofPushMatrix();
//        ofSetColor(2, 2, 2);
        ofSetColor(255, 160, 122);
//        ofSetColor(230);

        ofRotate(-_theta);
        ofEllipse(-h, h*level*100, 1, 20);
        //    line(0,0,0,-h);
        ofTranslate(0, -1.2*h);
        branch(h,_theta,level);
        ofPopMatrix();
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
