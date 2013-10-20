#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetBackgroundAuto(true);

    
    box2d.init();
	box2d.setGravity(0, 10);
	box2d.createBounds();
	box2d.setFPS(30.0);
	box2d.registerGrabbing();
    value=0;
    
    float r = ofRandom(30, 50);		// a random radius 4px - 20px
    ofxBox2dCircle circle;
    circle.setPhysics(3.0, 0.53, 0.1);
    circle.setup(box2d.getWorld(), ofGetWindowWidth()-60, 60, r);
    circle.addForce(ofVec2f(ofRandom(-300,0),1), 10);
    circles.push_back(circle);
    
    ofImage tempImage;
    tempImage.loadImage("image3.png");
    tempImage.resize(r*2,r*2);
    images.push_back(tempImage);

}

//--------------------------------------------------------------
void testApp::update(){
    timer = ofGetElapsedTimef()-value;
    box2d.update();
    if(timer>1){
        value=ofGetElapsedTimef();
        float r = ofRandom(30, 50);		// a random radius 4px - 20px
		ofxBox2dCircle circle;
		circle.setPhysics(3.0, 0.53, 0.1);
		circle.setup(box2d.getWorld(), ofGetWindowWidth()-60, 60, r);
        circle.addForce(ofVec2f(ofRandom(-300,0),1), 10);
		circles.push_back(circle);
        
        ofImage tempImage;
        tempImage.loadImage("image3.png");
        tempImage.resize(r*2,r*2);
        images.push_back(tempImage);
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	for(int i=0; i<circles.size(); i++) {
        ofSetColor(255);
        ofNoFill();
        float rotate = circles[i].getRotation();
        float radius = circles[i].getRadius();
        ofPushMatrix();
        ofTranslate(circles[i].getPosition().x, circles[i].getPosition().y);
        ofRotateZ(circles[i].getRotation());
        images[i].draw(-radius,-radius);
        ofPopMatrix();
	}

    box2d.drawGround();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'c') {

	}
    
    if(key == 't') ofToggleFullscreen();
    

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
