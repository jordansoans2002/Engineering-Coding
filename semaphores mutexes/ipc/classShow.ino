#include <Arduino_FreeRTOS.h>
#define  configUSE_PREEMPTION 1
#define configUSE_MUTEXES 1
#define uxTaskPriorityGet 1
#include "semphr.h"
#include "task.h"

void task1(void *param);
void task2(void *param);

TaskHandle_t taskHandle1;
TaskHandle_t taskHandle2;
TaskHandle_t taskHandle3;

SemaphoreHandle_t disp=NULL;
SemaphoreHandle_t binarySem=NULL;
SemaphoreHandle_t xMutex=NULL;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  vSemaphoreCreateBinary(disp);
  xMutex=xSemaphoreCreateMutex();
  //vSemaphoreCreateBinary(xMutex);
  vSemaphoreCreateBinary(binarySem);
  xSemaphoreTake(binarySem,0);
 
  xTaskCreate(task3,"Task 3",100,NULL,1,&taskHandle3);
  xTaskCreate(task2,"Task 2",100,NULL,2,&taskHandle2);
  xTaskCreate(task1,"Task 1",100,NULL,3,&taskHandle1);
  vTaskSuspend(taskHandle1);
  
  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void task1(void *param){
  (void) param;
  Serial.print(F("T1e "));
  vTaskDelay(10000/portTICK_PERIOD_MS);
  //waiting for mutex held by task 3
  xSemaphoreTake(xMutex,portMAX_DELAY);
  while(1){
    Serial.print(F("T1 "));
    vTaskDelay(500000/portTICK_PERIOD_MS);
  }
}
void task2(void *param){
  (void) param;
  Serial.println(F("T2e"));
  vTaskDelay(10000/portTICK_PERIOD_MS);

  //waiting for task 3 to release semaphore
  xSemaphoreTake(binarySem,portMAX_DELAY);
 
  while(1){
    Serial.print(F("T2 "));
    vTaskDelay(500000/portTICK_PERIOD_MS);
  }
}
void task3(void *param){
  (void) param;
  int i;
  //take mutex so task 1 cant run
  xSemaphoreTake(xMutex,portMAX_DELAY);
  Serial.println("3mt");
  vTaskDelay(10000/portTICK_PERIOD_MS);

  for(i=1;;i++){
    if(i==3){
      Serial.println(F("sg"));
      //give semaphore to task 2
      xSemaphoreGive(binarySem);
      //task 2 starts running
    }
    if(i==5){
      Serial.println(F("tr"));
      //resume suspended task 1
      vTaskResume(taskHandle1);
    }
    if(i==8){
      Serial.println(F("mg"));
      //give mutex to task 1
      xSemaphoreGive(xMutex);
    }
    Serial.print(F("T3 "));
    if(i==10){
      Serial.println("bas hoagaya na");
      vTaskDelete(taskHandle1);
      vTaskDelete(taskHandle2);
      vTaskDelete(NULL);
    }
    vTaskDelay(500000/portTICK_PERIOD_MS);
  }
}
