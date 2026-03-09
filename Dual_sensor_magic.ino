const int trigPin = 11;//left sensor
const int echoPin = 10;
const int vibeboardPin = 12;
const int ledPin =  13;

const int trigPin_2 = 3;//right sensor
const int echopin_2 = 4;
const int vibeboardPin_2= 2;
const int T1= A1;
const int T2= A2;
const int T3= A3;
const int T4= A4;
const int T5= A5;






long duration, distance, UltraSensor1, UltraSensor2; 

void setup() {
  // put your setup code here, to run once:

  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(vibeboardPin, OUTPUT);
  pinMode (trigPin_2, OUTPUT);
  pinMode (echopin_2, INPUT);
   pinMode (T1, OUTPUT);
  pinMode (T2,OUTPUT);
  pinMode (T3,OUTPUT);
   pinMode (T4,OUTPUT);
    pinMode (T5,OUTPUT);
  

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:


  SonarSensor(trigPin, echoPin);              // look bellow to find the definition of the SonarSensor function
UltraSensor1 = distance;                      // store the distance in the first variable
SonarSensor(trigPin_2,echopin_2);               // call the SonarSensor function again with the second sensor pins
UltraSensor2 = distance; 

  Serial.print(" "); 
  Serial.print("distance-1  " );//left sensor
Serial.print(UltraSensor1);
Serial.println(" cm");
//----------------------------------------------------------------------------------------------------------------------

//display the distance on the serial monitor for the second sensor
//----------------------------------------------------------------------------------------------------------------------
Serial.print("   distance-2   ");//right sensor
Serial.print(UltraSensor2);

Serial.println(" cm");
 if (UltraSensor1 <20 || UltraSensor2<20) //To trigger Stop (T3) Range 0-20cm 
 {
   Serial.print("STOP ");
  

   digitalWrite(T3,HIGH);
  delay(10);
  digitalWrite(T3,LOW);
  delay(1000);
 

    //digitalWrite(ledPin, HIGH);
    digitalWrite(vibeboardPin, HIGH);
    
    

  }
   else if (UltraSensor1 <230 || UltraSensor2 <230)  //To trigger Approaching Left (T4) Range(20-200)cm
   {
  
   if (UltraSensor1<UltraSensor2)
   {
  Serial.print("Left Approaching");
  
  digitalWrite(T4,HIGH);
  delay(10);
  digitalWrite(T4,LOW);
  delay(1500);
  
  digitalWrite(vibeboardPin, HIGH);
  delay(250);
  digitalWrite(vibeboardPin, LOW);
  delay(500);

   
   }

  if (UltraSensor1>UltraSensor2)  // To trigger Approaching Right (T5) Range(20-200)cm
  {
  Serial.print("Right Approaching");
  

  digitalWrite(T5,HIGH);
  delay(10);
  digitalWrite(T5,LOW);
  delay(1500);
 
  digitalWrite(vibeboardPin, HIGH);
  delay(250);
  digitalWrite(vibeboardPin, LOW);
  delay(500);


  }

  
  if(UltraSensor1== UltraSensor2) //To trigger Approaching (T2) Range(20-200)cm
  {
  Serial.print("Approaching");
  

  digitalWrite(T2,HIGH);
  delay(10);
  digitalWrite(T2,LOW);
  delay(1900);
 

  digitalWrite(vibeboardPin, HIGH);
  delay(250);
  digitalWrite(vibeboardPin, LOW);
  delay(500);

  }
  
  }
   
   
   
   
   
   else if (UltraSensor1 <300 || UltraSensor2 <300) // To trigger Within Range (T1) Max range=400cm   
   {

     Serial.print("Within Range");
     

     digitalWrite(T1,HIGH);
  delay(10);
  digitalWrite(T1,LOW);
  delay(1500);
   
    }



 else {  
    digitalWrite(ledPin, LOW);
    digitalWrite(vibeboardPin,LOW);
    digitalWrite(vibeboardPin_2, LOW);
  }





}

  
 void SonarSensor(int trigPinSensor,int echoPinSensor)//it takes the trigPIN and the echoPIN 
{
  //START SonarSensor FUNCTION
  //generate the ultrasonic wave
//---------------------------------------------------------------------------------------------------------------------- 
digitalWrite(trigPinSensor, LOW);// put trigpin LOW 
delayMicroseconds(2);// wait 2 microseconds
digitalWrite(trigPinSensor, HIGH);// switch trigpin HIGH
delayMicroseconds(10); // wait 10 microseconds
digitalWrite(trigPinSensor, LOW);// turn it LOW again
duration = pulseIn(echoPinSensor, HIGH);//pulseIn funtion will return the time on how much the configured pin remain the level HIGH or LOW; in this case it will return how much time echoPinSensor stay HIGH
distance= (duration/2) / 29.1; // first we have to divide the duration by two  
}// END SonarSensor FUNCTION









  
