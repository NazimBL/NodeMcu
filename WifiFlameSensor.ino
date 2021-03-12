/* Flame Sensor digital example.
 
Code by Belabbaci Nazim (https://github.com/NazimBL)
Flame Sensor Ordered from Deadline Store: https://www.facebook.com/thedeadlinestore/

*/

//internal led D4
#define LED 2
// GPIO5 is pin D1 on the Node Mcu board
#define BUZZER 5
// D5
#define SENSOR 14


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "mBpYsGNm3P5JiFxVK4ehss_o7c_mNDl5";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "OPPO A31";
char pass[] = "12345678";



WidgetLED led2(V2); //register to virtual pin 2
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(SENSOR,INPUT);
  

  digitalWrite(BUZZER,0);
  digitalWrite(LED,0);
  led2.off();

}

void loop() {
  
  Blynk.run(); 
  //inverted logic
  if(digitalRead(SENSOR)==0){
    
    digitalWrite(BUZZER,1);
    digitalWrite(LED,1);  
    Blynk.notify(" FLAMME detected!");
    led2.on();
   
    
   }else{
      digitalWrite(BUZZER,0);
      digitalWrite(LED,0);
      led2.off();
     
    } 
}
