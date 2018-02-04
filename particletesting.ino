char mystr[50]; //Initialized variable to store recieved data
String outputvalue; 

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
   Serial.readBytes(mystr,50); 
  delay(2000);
}

outputvalue = String(mystr); 
Particle.variable("output", &outputvalue, STRING); 
  
}
