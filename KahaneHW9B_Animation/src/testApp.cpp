#include "testApp.h"
//THIS WAS GOING TO HAVE STRETCH DEPENDING ON THE SPEED OF THE BATS BUT RESIZING THE IMAGES SORT OF KILLED EVERYTHING

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);

    song.loadSound("song.mp3");
    song.setVolume(1.0f);
    song.play();
    
    box2d.init();
	box2d.setGravity(0, 5);
//	box2d.createBounds();
	box2d.setFPS(30.0);
	box2d.registerGrabbing();
    value=0;
    
    float r = ofRandom(30, 50);		// a random radius 4px - 20px
    ofxBox2dCircle circle;
    circle.setPhysics(3.0, 0.53, 0.1);
    circle.setup(box2d.getWorld(), -50, ofRandom(ofGetWindowHeight()), r);
    circle.addForce(ofVec2f(ofRandom(300,400),ofRandom(-200,-400)),10);
    circles.push_back(circle);
    
    ofImage tempImage;

    tempImage.loadImage("image2.png");
//    tempImage.resize(r*2,r*2);
    images.push_back(tempImage);

}

//--------------------------------------------------------------
void testApp::update(){
    timer = ofGetElapsedTimef()-value;
    box2d.update();
    if(timer>.002){
        value=ofGetElapsedTimef();
        float r = ofRandom(30, 50);		// a random radius 4px - 20px
		ofxBox2dCircle circle;
		circle.setPhysics(3.0, 0.53, 0.1);
        circle.setup(box2d.getWorld(), -50, ofRandom(ofGetWindowHeight()), r);
        circle.addForce(ofVec2f(ofRandom(300,400),ofRandom(-200,-400)),10);
        b2Fixture* f = circle.body->GetFixtureList();
        b2Filter filter = f->GetFilterData();
        filter.categoryBits = 0x0006; //birds
        filter.maskBits = 0x0001; //boundaries
        f->SetFilterData(filter);
		circles.push_back(circle);
        
        ofImage tempImage;
        tempImage.loadImage("image2.png");
//        tempImage.resize(r*2,r*2);
        images.push_back(tempImage);
        
    }
    
    for(int i=0; i<circles.size(); i++){
        float stretch = (abs(circles[i].getVelocity().x) + abs(circles[i].getVelocity().y));
//        images[i].loadImage("image2.png");
//        images[i].resize(circles[i].getRadius()*2, circles[i].getRadius()*2+stretch*4);
    }
    
    ofLog( OF_LOG_NOTICE, "size is " + ofToString(images.size()) );
    
    for( vector<ofxBox2dCircle>::iterator it=circles.begin(); it!=circles.end(); ){
        
        if(it->getPosition().x>ofGetWindowWidth() || it->getPosition().y>ofGetWindowHeight()){
            circles.erase(it);
            images.pop_back();
        }else {
            it++;
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor colorOne;
    ofColor colorTwo;
    
    colorTwo.set (0,0,0);
    colorOne.set (255,0,0);
    
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
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
