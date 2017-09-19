
/******************************
* Processing Workshop
* Coderdojo Waterford, Arclabs,
* Waterford City
* September 2017
* South East Makerspace 
* Licence: GPL 3.0
******************************/

int circSize = 10; 
int col = 0;

void setup() {
  fullScreen();
  //size(800, 600);  
  background(0); // one val is greyscale or 3 vals background(r,g,b) colour 
  frameRate(25); // change to speed up o slow down
}

void draw() {
  // CREATES FADING EFFECT WITH OPACITY VALUE in fill
  fill(0, 5);
  noStroke();
  rect(0, 0, width, height);

  //DRAW CIRCLE  (Rectangles, lines, points are other possibilities)
  stroke(255);
  strokeWeight(3);
  fill(col, 0, col);
  // point( random(0,600), random( 0, 600));
  ellipse( random( 0, width), random( 0, height), circSize, circSize);

  // KEEP CIRCLE IN BOUNDS so no negative values - could also define a maximum
  if (circSize <=10 ) {
    circSize = 10;
  }
}


void keyPressed() {
  if (key == 'q' ) {
    circSize = circSize + 10;
  }
  if (key == 'w' ) {
    circSize = circSize - 10;
    //println(circSize);
  }
  if (key == 'e') {
    background( random(255), 0, 155);
  }
  if (key == 'r') {
    col = int(random(0, 255));
   // println(col);
  }
  
  //saveFrame("img-#####.jpg");
}
