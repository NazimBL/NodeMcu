
TaskHandle_t task1;

void taskHandler1(void * param){
  
    
   while(1)
    {
        Serial.print("Task1 Running on core : ");
        Serial.println(xPortGetCoreID());
        delay(200);
        //vTaskDelay(250/portTICK_PERIOD_MS);
    }

  
  
  }

void setup() {
  // put your setup code here, to run once:
 pinMode(2, OUTPUT);
 Serial.begin(9600);
 xTaskCreatePinnedToCore(taskHandler1, "Task1", 1020, NULL, 1, &task1,0);

 //xTaskCreate(taskHandler1, "Task1", 1020, NULL, 1, &task1);
 
}

void loop() {
  // put your main code here, to run repeatedly:

Serial.print("Loop function core : ");
Serial.println(xPortGetCoreID());
    delay(1000);

}
