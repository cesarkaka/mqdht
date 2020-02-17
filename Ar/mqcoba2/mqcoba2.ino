#include <Wire.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
int sensorValue;
float q;
void setup(){ 
Serial.begin(9600);                            // sets the serial port to 9600
dht.begin();
 }
void loop(){sensorValue = analogRead(0);  // read analog input pin 0
float h = dht.readHumidity();
float t = dht.readTemperature();
Serial.print("AirQua=");
Serial.print(sensorValue);               // prints the value read
Serial.print(" PPM");
q = sensorValue / 10000.0000;
Serial.print("   Persen=");
Serial.print(q,5);
Serial.println(" %");
Serial.print("Humidity: ");
Serial.print(h);
Serial.print("%   Temperature: ");
Serial.print(t);  
Serial.println("°C ");
delay(1000);                                   // wait 100ms for next reading
}
