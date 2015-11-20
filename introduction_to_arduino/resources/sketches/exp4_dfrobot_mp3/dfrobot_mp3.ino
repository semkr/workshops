/∗
Sample code to work with the DFPlayer Mini MP3 Player
Author: David Kirwan
Licence: Apache 2.0
∗/

#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

boolean playing;

void setup(){
  Serial.begin(9600);
  mp3_set_serial(Serial);
  delay(1);
  mp3_set_volume(7);
  playing = false;
}

void loop(){
  if(!playing){
    playing = true;
    mp3_play();
  }
  
}

