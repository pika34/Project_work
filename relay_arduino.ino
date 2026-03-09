
/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-relay
 */

// constants won't change







int RELAY_PIN = 13;  // the Arduino pin, which connects to the IN pin of relay

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{


  if (Serial.available() >0){

   String msg = Serial.readString();
   
    
 if (msg == "ON")
 {
    

  
  digitalWrite(RELAY_PIN, HIGH);
  
  }
  else if(msg=="OFF"){
  digitalWrite(RELAY_PIN, LOW);
  
  }
}
}
