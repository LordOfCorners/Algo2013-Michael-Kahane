#pragma once

#include "ofMain.h"
#include "FlowField.h"
#include "Particle.h"
#include "ofxUI.h"
#include "ofxPostProcessing.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void onGuiEvent( ofxUIEventArgs &e );
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    FlowField myField;
    vector<Particle>    particleList;
    void addParticle();
    ofVideoGrabber vid;

    double  lastTime;
    float   timeScale;
    int counter =0;
    ofxUICanvas *gui;

};
