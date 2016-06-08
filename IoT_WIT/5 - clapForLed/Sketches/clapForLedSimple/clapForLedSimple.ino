//global variables
int readValue;
int maximumValue;
int minimumValue; 


// will reset maximum and minimum values only when we call it
void resetMaximumAndMinimum() 
{
  maximumValue = 0;             // set maximum to lowest value possible
  minimumValue = 32767;         // set minimum to highest value possible
}


// this runs only once on the startup
void setup() 
{
  // initialize built-in LED light at digital pin 13 as an output
  pinMode(13, OUTPUT);           
  resetMaximumAndMinimum();
}


// the loop runs over and over again forever
void loop() 
{
  // read current value from the microphone
  readValue = analogRead(A0);     

  // if read value is smaller than minimum then set it as the new minimum
  if (readValue < minimumValue)   
  {
    minimumValue = readValue;     
  }

  // if read value is bigger than maximum then set it as the new maximum
  if (readValue > maximumValue)   
  {
    maximumValue = readValue;     
  }

  // Change the 10 constant to adjust the sensitivity.
  //   To 20 if you want the light triggered on louder claps   
  //   Ti 5  if you want the light triggered on quieter noises 
  //   Feel free to experiment with the values.
  if ( (maximumValue - minimumValue) > 10 ) 
  {
    digitalWrite(13, HIGH);       // turn the LED on (HIGH is the voltage level)
    delay(2 * 1000);              // wait for 2 seconds (2 * 1000ms)
    digitalWrite(13, LOW );       // turn the LED off by making the voltage LOW

    // if we wouldn't clear the max & min then after first trigger it would get 
    // triggered every single time no matter what read values were
    resetMaximumAndMinimum();     
  }
}
