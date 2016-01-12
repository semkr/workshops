/*
Phenakistoscope
Turns on an LED on then off 20 times a second in order to activate the Phenakistoscope
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // turn the LED on 
  // (HIGH is the voltage level)
  digitalWrite(13, HIGH);
      
  //wait for 50 milliseconds
  delay(50);
        
  // turn the LED off by making 
  // the voltage LOW
  digitalWrite(13, LOW);    
                      
  // wait for 30 milliseconds              
  delay(30);
}
