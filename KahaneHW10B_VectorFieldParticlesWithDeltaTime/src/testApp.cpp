#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 10 );
    particleList.clear();
    vid.initGrabber(ofGetWindowWidth(),ofGetWindowHeight(),true);

    ofBackground(0);
    
    gui = new ofxUICanvas;
    
    gui->addSlider("timeScale", -3, 3, -0.01);
    gui->autoSizeToFitWidgets();

    ofAddListener(gui->newGUIEvent,this,&testApp::onGuiEvent);


    lastTime = ofGetElapsedTimef();
    timeScale = 0;
    
    //add particles
    for( int i=0; i<30000; i++ ){ //play with this number
        addParticle();
    }
    
}

void testApp::onGuiEvent(ofxUIEventArgs &e) {
    
    
    string name = e.widget->getName();
	int kind = e.widget->getKind();
    
    if( name == "timeScale" ){
        ofxUISlider *mySlider = (ofxUISlider *)e.widget;
        timeScale = mySlider->getScaledValue();
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
    float dt = ofGetElapsedTimef() - lastTime;
    lastTime = ofGetElapsedTimef();
    
    myField.update(vid);
    vid.update();
    
    cout << timeScale << endl;

    //add forces

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
        particleList[i].update( dt * timeScale);
        
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
    ofScale(-1,1);
    ofTranslate(-ofGetWindowWidth(),0);
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
    if (key == 's' || key == 'S'){
        string fileName = "screenshot_" + ofToString(counter) + ".png";
        ofSaveScreen(fileName);
        counter++;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
//    timeScale = ofMap( x, 0, ofGetWindowWidth(), -3, 3 );
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
