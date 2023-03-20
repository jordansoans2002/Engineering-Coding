#include <Arduino_FreeRTOS.h>
#define configUSE_MUTEXES 1
#include "semphr.h"
#include "task.h"

void task1(void *param);
void task2(void *param);

TaskHandle_t taskHandle1;
TaskHandle_t tashHandle2;
TaskHandle_t tashHandle3;

xSemaphoreHandle binarySem=NULL;
xSemaphoreHandle xMutex=NULL;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  xMutex=xSemaphoreCreateMutex();
  vSemaphoreCreateBinary(binarySem);
  xSemaphoreTake(binarySem);
  
  if(xMutex!=NULL){
      xTaskCreate(task3,"Task 3",100,NULL,1,&taskHandle3);
      xTaskCreate(task2,"Task 2",100,NULL,2,&taskHandle2);
  }
  
  xTaskCreate(task1,"Task 1",100,NULL,3,&taskHandle1);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void task1(void *param){
  (void) param;
  while(1){
    xSemaphoreTake(xMutex)
    Serial.println("T1");
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}
void task2(void *param){
  (void) param;
  xSemaphoreTake(binarySem,10);
  int i;
  for(i=0;;i++){
    Serial.println("T2");
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}
void task3(void *param){
  (void) param;
  int i;
  for(i=0;;i++){
    Serial.println("T3");
    if(i==5)
      xSemaphoreGive(binarySem,10);
    if(i==100)
      xSemaphoreGive(xMutex);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}
