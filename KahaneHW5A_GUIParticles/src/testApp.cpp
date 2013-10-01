#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    /*****COOL SETTINGS*****
    
    FireWorks
     backgroundToggle: True (draws background)
     Radius: 7
     Explosion Range 102-741
    
    Trees
     backgroundToggle: False (no background drawing)
     Radius: 9
     ExplosionRange 450-670
    
    Big Blobs
     backgroundToggle: True (draws background)
     Radius: 50
     Explosion Range 0-768
    
    ************************/
    

    
    
    launcher.minimum=300;
    launcher.maximum=600;
    radius=10;
    gui = new ofxUICanvas();
    gui->addLabel("Firework controls");
    gui->addSpacer();
    gui->addToggle("backgroundToggle",true,40,40);
    gui->addSlider("radius",0,50.0,10.0);
	gui->addRangeSlider("explosionRange", 0.0, ofGetWindowHeight(), 300, 600); //IT'S REALLY EMBARRASSING HOW LONG THIS PARTICULAR ONE TOOK TO GET WORKING.

    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent);
    
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    ofSetFrameRate(60);
    
    launcher.setup();

}

void testApp::exit(){
    delete gui;
}

void testApp::onGuiEvent(ofxUIEventArgs &e){
    cout <<"I got a message" << e.getName() << endl;
    
    if(e.getName() == "radius"){
        ofxUISlider *radiusSlider = (ofxUISlider*)e.widget;
        
        radius = radiusSlider->getScaledValue();
        
    }else if(e.getName() == "backgroundToggle"){
        ofxUIToggle *b = (ofxUIToggle*) e.widget;
        b->getValue();
        if(b->getValue()==true){
            drawBackground=true;
        }else if(b->getValue()==false){
            drawBackground=false;
        }
    }
    else if(e.getName() == "explosionRange")
    {
        ofxUIRangeSlider *explosionRange = (ofxUIRangeSlider *) e.widget;
        launcher.maximum = explosionRange->getScaledValueLow();
        launcher.minimum = explosionRange->getScaledValueHigh();
    }
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
void testApp::update(){
    // This is how you loop through and delete a particle using iterators and vectors
    // Note how we don't put it++ up in the top of the loop.
    for( vector<Particle>::iterator it=pList.begin(); it!=pList.end(); ){
        it->update();
        
        if( it->bIsDead ){
            it = pList.erase(it);   // When we erase one, it returns the next particle automatically.  It's done the "it++" for us!
//            ofLog( OF_LOG_NOTICE, "size is " + ofToString(pList.size()) );
        }else {
            it++;
        }
    }
    launcher.update();
    if(launcher.pos.y<launcher.explodeHeight && !launcher.dead){
        launcher.dead=true;
        
        for( vector<Particle>::iterator it=pList.begin(); it!=pList.end(); ){
            
            it = pList.erase(it);   // When we erase one, it returns the next particle automatically.  It's done the "it++" for us!
//            ofLog( OF_LOG_NOTICE, "size is " + ofToString(pList.size()) );
            
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
    if(drawBackground){
        ofRect(0,0,ofGetWindowWidth(),ofGetWindowHeight());
    }
    
    for( vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++){
        ofSetColor(launcher.color);
        it->draw(radius);
    }
    launcher.draw();
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
