#include <Arduino_FreeRTOS.h>
#define  configUSE_PREEMPTION 1
#define configUSE_MUTEXES 1
#define uxTaskPriorityGet 1
#include "semphr.h"
#include "task.h"

TaskHandle_t taskHandle1;
TaskHandle_t taskHandle2;
TaskHandle_t taskHandle3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  xTaskCreate(task3,"Task 3",100,NULL,1,&taskHandle3);
  xTaskCreate(task2,"Task 2",100,NULL,2,&taskHandle2);
  xTaskCreate(task1,"Task 1",100,NULL,3,&taskHandle1);
  vTaskSuspend(taskHandle1);
  
  vTaskStartScheduler();
}

void task1(void *param){
  (void) param;
  Serial.print(F("T1e "));
  vTaskDelay(10000/portTICK_PERIOD_MS);
 
  while(1){
    Serial.print(F("T1 "));
    vTaskDelay(500000/portTICK_PERIOD_MS);
  }
}
void task2(void *param){
  (void) param;
  Serial.println(F("T2e"));
  vTaskDelay(10000/portTICK_PERIOD_MS);
 
  while(1){
    Serial.print(F("T2 "));
    vTaskDelay(500000/portTICK_PERIOD_MS);
  }
}
void task3(void *param){
  (void) param;
  int i;
  for(i=1;;i++){
    if(i==3){
      Serial.println(F("tr"));
      //resume suspended task 1
      vTaskResume(taskHandle1);
    }
    Serial.print(F("T3 "));
    if(i==5){
      Serial.println("bas hoagaya na");
      vTaskDelete(taskHandle1);
      vTaskDelete(taskHandle2);
      vTaskDelete(NULL);
    }
    vTaskDelay(500000/portTICK_PERIOD_MS);
  }
}
