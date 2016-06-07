//global constants
#define noiseThreshold  10           // increasing it will make trigger less sensitive
#define microphonePin   A0           // analog  pin A0 is connected to microphone
#define ledPin          13           // digital pin 13 is connected to LED
#define ledTime          3           // LED will be lit for 3 seconds


// this runs only once on the startup
void setup() {
  // initialize desired ledPin as output
  pinMode(ledPin, OUTPUT);           
}


// the loop runs over and over again forever
void loop() {
  static unsigned int maximumValue =     0;
  static unsigned int minimumValue = 65535; 

  // read current value from the microphone
  unsigned int readValue = analogRead(microphonePin);  

  // if read value is bigger/smaller than our current max/min then update our max/min
  if (readValue < minimumValue) { 
    minimumValue = readValue;     
  }
  if (readValue > maximumValue) { 
    maximumValue = readValue;     
  }

  // if the noise was too loud lit the light
  if ( (maximumValue - minimumValue) > noiseThreshold ) {
    digitalWrite(ledPin, HIGH);      // turn the LED on (HIGH is the voltage level)
    delay(ledTime * 1000);           // wait for predefined time
    digitalWrite(ledPin, LOW );      // turn the LED off by making the voltage LOW
    
    maximumValue =     0;            // set maximum to lowest value possible
    minimumValue = 65535;            // set minimum to highest value possible
  }
}
