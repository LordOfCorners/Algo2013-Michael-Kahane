float catchUp;
float sinOfTimeMapped;
Eyeball leftEye, rightEye;
PVector facePos;

void setup(){
    size(1024,768);  //P3D allows the 3d rendering
    background(255);
    smooth();
    leftEye = new Eyeball();
    leftEye.pos = new PVector( width/2 - 75, height * 0.5 );
        
    rightEye = new Eyeball();
    rightEye.pos = new PVector( width/2 + 75, height * 0.5 );
    
    facePos = new PVector(width/2,height/2);
    catchUp = 0.03f;
}

void draw(){
    //update
    facePos.x = catchUp * mouseX + (1-catchUp) * facePos.x;
    facePos.y = catchUp * mouseY + (1-catchUp) * facePos.y;
    
    float sinOfTime = sin( millis()/1000.0*2 );
    sinOfTimeMapped = map( sinOfTime, -1, 1, 400, 500);
    //draw 
    background(255);
    leftEye.draw(new PVector(-60,0));
    rightEye.draw(new PVector(60,0));
    
    noFill();
    ellipse(facePos.x,facePos.y+50,sinOfTimeMapped,sinOfTimeMapped);
    bezier(facePos.x-15,facePos.y+70,facePos.x+5,facePos.y+90, facePos.x+15,facePos.y+90, facePos.x+25,facePos.y+70);
    bezier(facePos.x-100,facePos.y+200,facePos.x,facePos.y+250, facePos.x+50,facePos.y+250, facePos.x+100,facePos.y+200);
}
