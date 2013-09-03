#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    slowRect.setup(ofPoint(10,50), ofColor(100,100,255),NULL,20,20);
    fastRect.setup(ofPoint(10,140), ofColor(200,250,150),NULL,20,20);
    
    for(int i=0;i<sizeof(xenoRect)/sizeof(*xenoRect);i++){
        xenoRect[i].setup(ofPoint(0,300), ofColor(0,10*i+50,150+5*i), (0.01f*i)+0.05f,20,20);
    }
    
    ofSetColor(255);
    a.x = 20;
    a.y = 200;
    b.x = 200;
    b.y = 200;
}

//--------------------------------------------------------------
void testApp::update(){
    //Slowest non-moving speed
    slowRect.update(.0006);
    
    //Fastest non-moving speed
    fastRect.update(25);
    
    //Multiple Xenos
    if(!trails){
        for(int i=0;i<sizeof(xenoRect)/sizeof(*xenoRect);i++){
            xenoRect[i].xenoToPoint(mouseX, mouseY);
        }
    }
    //Multiple Xeno Trail
    else if(trails){
        xenoRect[0].xenoToPoint(mouseX, mouseY);
        for(int i=1;i<sizeof(xenoRect)/sizeof(*xenoRect);i++){
            xenoRect[i].xenoToPoint(xenoRect[i-1].pos.x, xenoRect[i-1].pos.y);
        }
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(15);
    
    //Slowest moving speed
    slowRect.displayInfo(ofPoint(0,0));
    slowRect.draw();
    
    //Fastest moving speed
    fastRect.displayInfo(ofPoint(0,90));
    fastRect.draw();
    
    //Click to change Point A and Point B
    ofSetColor(255,150,150);
    ofDrawBitmapString("Click to change point A or B (alternating)", 0 , 180);
    ofLine(a.x,a.y,b.x,b.y);
    ofDrawBitmapString("A", a.x, a.y);
    ofDrawBitmapString("B", b.x, b.y);
    
    //Multiple Xenos
    ofSetColor(240);
    ofDrawBitmapString("Press X turn on the Xeno array and T to toggle the trail effect", 0 , 300);
    if(drawXenos){
        for(int i=0;i<sizeof(xenoRect)/sizeof(*xenoRect);i++){
            xenoRect[i].draw();
        }
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key=='t'){
        trails =!trails;
    }
    if(key=='x'){
        drawXenos=!drawXenos;
    }
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
    clickCount+=1;
    if(clickCount%2==0){
        a.x=x;
        a.y=y;
    }
    else{
        b.x=x;
        b.y=y;
    }
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
