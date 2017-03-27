// define trigger and echo pins
#define trigPin 13
#define echoPin 12

void setup() {
  Serial.begin(9600); //Start serial monitor for debugging and display 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  //create a 10 second pulse to measure distance 
  long duration, distance;
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2);
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
   duration = pulseIn(echoPin, HIGH);
    
    // Distance based on the speed of sound at 68 degrees fahrenheit (343.5 m/s)
    // (343.5 m/s = 0.03435 cm/ ms = 1/29.1)
    // Distance = (duration from transmit to recieve/2)/29.1 
    
   distance = (duration/2) / 29.1;
   
   if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range");
   }
   else {
    Serial.print(distance);
    Serial.println(" cm");
   }
   delay(500);
}

