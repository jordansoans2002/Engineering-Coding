#include <Arduino_FreeRTOS.h>

void setup() {
  Serial.begin(9600);
  
  xTaskCreate(task1,"Task1",100,NULL,1,NULL);
  xTaskCreate(task2,"Task2",100,NULL,1,NULL);

//  xTaskCreate(task,"Task1",100,1,1,NULL);//pass a number to the task
//  xTaskCreate(task,"Task2",100,2,1,NULL);
  //vTaskStartScheduler();
}

void loop() {}

void task(int n){
  while(1){
    Serial.println("Task "+n);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void task1(void *param){
  (void) param;
  while(1){
    Serial.println("Task1");
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}
void task2(void *param){
  (void) param;
  while(1){
    Serial.println("Task1");
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}
