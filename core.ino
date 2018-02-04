#include <dht.h>

dht DHT;
#define DHT11_PIN 7

//noise indicator
int buzzer = 4;

//gas
int smoke = A5;
int sensorThres = 50;

//resistor
int resistor = A2; //define analog pin 2
int valueRes = 0;
int count = 0;

//sound
int potSound = A0; // select the input pin for the potentiometer
int soundValue = 8; // variable to store the value coming from the sensor

//sensor function
void tempAndHumid();
void bigSound();
void gasSensor();
void lcdscreen();

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(smoke, INPUT);
}

void loop()
{
  digitalWrite(buzzer, LOW);
  valueRes = analogRead(resistor);

  if (valueRes >= 100)
  {
    Serial.print(",");
    Serial.print("0");
    Serial.println(",");
    valueRes = analogRead(resistor);

    if (valueRes < 100)
    {
      count++;
      Serial.print(",");
      Serial.print("0");
      Serial.println(",");
      //Serial.print("Person: ");
      Serial.print(",");
      Serial.print(count);
      Serial.print(",");
      tempAndHumid();
      bigSound();
      gasSensor();
      digitalWrite(buzzer, HIGH);
      Serial.println();
      delay(50);
    }
  }
}

void tempAndHumid()
{
  delay(100);
  int chk = DHT.read11(DHT11_PIN);
  delay(100);
  //Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print(",");
  //Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.print(",");
}

void bigSound()
{
  soundValue = analogRead (potSound);
  //Serial.print("Sound level = ");
  Serial.print(soundValue, DEC);
  Serial.print(",");
}

void gasSensor()
{
  int analogSensor = analogRead(smoke);
  if (analogSensor >= sensorThres)
  {
    //Serial.print("Gas level DANGEROUS: ");
    Serial.print(analogSensor);
    Serial.print(",");
  }
  else
  {
    //Serial.print("Gas level SAFE: ");
    Serial.print(analogSensor);
    Serial.print(",");
  }
  delay(100);
}