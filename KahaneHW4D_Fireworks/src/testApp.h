#pragma once

#include "ofMain.h"
#include "Particle.h"

class Launcher {
public:
    ofPoint pos;
    ofVec2f vel;
    bool dead;
    int explodeHeight;
    ofColor color;

    void setup(){
        pos.x = ofRandom(ofGetWindowWidth());
        pos.y=ofGetWindowHeight()+20;
        vel.y=-5;
        vel.x=ofRandom(-1,1);
        dead=false;
        explodeHeight=ofRandom(150,450);
        color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
        
    }
    
    void update(){
        pos+=vel;
    }
    
    void draw() {
        ofSetColor(277,207,87);
        if(!dead) ofEllipse(pos.x,pos.y,2,10);
    }
    
};


class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void addParticle(ofPoint _launcherPos);
    
    vector<Particle> pList;
    Launcher launcher;
};
