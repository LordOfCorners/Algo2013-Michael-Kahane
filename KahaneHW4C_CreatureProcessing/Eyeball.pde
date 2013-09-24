class Eyeball {
  PVector offset, pos; 
  float angle;

  Eyeball(){
  }
  
  void draw(PVector _offset) {
    offset = _offset;
    pushMatrix();

    pos.x = catchUp * mouseX + (1-catchUp) * pos.x;
    pos.y = catchUp * mouseY + (1-catchUp) * pos.y;
   
    translate((pos.x+offset.x),(pos.y+offset.y));

    float dx = mouseX - (pos.x+offset.x);
    float dy = mouseY - (pos.y+offset.y);
    angle = atan2( dy, dx );
    rotate(angle);
    
    color(0);
    
    //outline
    noFill();
    ellipse(0,0,100,100);
    
    //pupil
    fill(0);
    ellipse(25,0,40,40);

    popMatrix();
  }
}

