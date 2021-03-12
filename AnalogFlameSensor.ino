/* Flame Sensor analog example.
 
Code by Belabbaci Nazim (https://github.com/NazimBL)
Flame Sensor Ordered from Deadline Store: https://www.facebook.com/Deadline-store-108541264043274

*/

//internal led
#define LED 2
// GPIO5 is pin D1 on the Node Mcu board
#define BUZZER 5

// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void setup() {
  
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  
    
}
void loop() {
  
 
	int sensorReading = analogRead(A0);
  
  // convert adc value to range in feet (max range is 3 feet)
	int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    Serial.println("** Close Fire **");
    digitalWrite(LED,1);
    digitalWrite(BUZZER,1);
    
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("** Distant Fire **");
    digitalWrite(LED,1);
    digitalWrite(BUZZER,0);
    break;
  case 2:    // No fire detected.
    Serial.println("No Fire");
    digitalWrite(LED,0);
    digitalWrite(BUZZER,0);
    break;
  }
  delay(1);  // delay between reads
}
