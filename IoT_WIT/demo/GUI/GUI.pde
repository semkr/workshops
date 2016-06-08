import processing.serial.*;

final int     PORT_TO_OPEN   = 4;
final int     PORT_BAUD_RATE = 115200;
final boolean VERBOSE        = false;
final int     PORT_LINE_FEED = 10;      //new line character 

int x               = 1;                // horizontal position of the graph 
int lastMicrophone  = 1;                // vertical value for microphone
int lastLight       = 1;                // vertical value for light
int lastTemperature = 1;                // vertical value for temperature

Serial myPort;       

void setup() {
  size(800, 900);
  
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[PORT_TO_OPEN], PORT_BAUD_RATE);
  myPort.bufferUntil(PORT_LINE_FEED);

  background(255); 
  strokeWeight(4);        
  stroke(0,0,0);    
}

void draw() { 
  //needs to be present or the serialEvent woudn't get called
} 

void serialEvent(Serial myPort) {
  String myString = myPort.readStringUntil(PORT_LINE_FEED);

  if (myString != null) {
    
    myString = trim(myString);

    int values[] = int(split(myString, ','));
    
    if (values.length == 3 ) {
      if (VERBOSE) {
        for (int i = 0; i < values.length; i++) {
          print("Value " + i + ": " + values[i] + "\t\t");
        }
        println();
      }
      
      int microphone  = (int)map(values[0], 0, 400,     height/3,            0);
      int light       = (int)map(values[1], 0, 100, (height*2)/3,     height/3);
      int temperature = (int)map(values[2], 0, 100,       height, (height*2)/3);
      
      line(x-1, lastMicrophone,  x, microphone ); 
      line(x-1, lastLight,       x, light      ); 
      line(x-1, lastTemperature, x, temperature);
     
      lastMicrophone  = microphone;
      lastLight       = light; 
      lastTemperature = temperature;

      if (x >= width) {
        x = 0;
        background(255); 
      } 
      x++;
    }
  }
}


