#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "tornado.h"
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
    
    void checkOsc();
    ofxOscReceiver  mReceiver;
    
    float bgColor;
    
    ofEasyCam cam;
    Tornado myTornado;
    vector<Tornado> tornadoList;
    ofColor color;
    float lineThickness;
    int volume; 
};
