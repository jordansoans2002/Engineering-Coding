#include <Arduino_FreeRTOS.h>
#define  configUSE_PREEMPTION 1
#define configUSE_TIME_SLICING 1
#define configUSE_MUTEXES 1
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
  vSemaphoreCreateBinary(binarySem);
  xSemaphoreTake(binarySem,0);
  xSemaphoreTake(xMutex,0);

  if(xMutex!=NULL){
      xTaskCreate(task3,"Task 3",100,NULL,1,&taskHandle3);
      xTaskCreate(task2,"Task 2",100,NULL,2,&taskHandle2);
  }
  xTaskCreate(task1,"Task 1",100,NULL,3,&taskHandle1);
  vTaskStartScheduler();

}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void task1(void *param){
  (void) param;
  xSemaphoreTake(disp,2);
  Serial.println("T1e");
  xSemaphoreGive(disp);
  vTaskDelay(10000/portTICK_PERIOD_MS);
  while(1){
    xSemaphoreTake(xMutex,0);
    xSemaphoreTake(disp,2);
    Serial.println(F("T1"));
    xSemaphoreGive(disp);
    vTaskDelay(10000/portTICK_PERIOD_MS);
  }
}
void task2(void *param){
  (void) param;
  xSemaphoreTake(binarySem,0);
  xSemaphoreTake(disp,2);
  Serial.println(F("T2s"));
  xSemaphoreGive(disp);
  vTaskDelay(10000/portTICK_PERIOD_MS);
 
  int i;
  for(i=0;;i++){
    xSemaphoreTake(disp,0);
    Serial.println(F("T2"));
    xSemaphoreGive(disp);
    vTaskDelay(30000/portTICK_PERIOD_MS);
  }
}
void task3(void *param){
  (void) param;
  int i;
  xSemaphoreTake(disp,0);
  Serial.println("T3e");
  xSemaphoreGive(disp);
  vTaskDelay(10000/portTICK_PERIOD_MS);
  for(i=0;;i++){
//    xSemaphoreTake(disp,0);
//    Serial.println(F("T3"));
//    xSemaphoreGive(disp);
    if(i==500){
      xSemaphoreTake(disp,0);
      Serial.println(F("sg"));
      xSemaphoreGive(disp);
      xSemaphoreGive(binarySem);
    }
    if(i==1000){
      xSemaphoreTake(disp,2);
      Serial.println(F("mg"));
      xSemaphoreGive(disp);
      xSemaphoreGive(xMutex);
    }
    vTaskDelay(30000/portTICK_PERIOD_MS);
  }
}
