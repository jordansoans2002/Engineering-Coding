// LCD1602 to Arduino Uno connection example

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

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
  lcd.begin(20, 4);

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
  // xSemaphoreTake(disp,portMAX_DELAY);
  Serial.print(F("T1e"));
  // xSemaphoreGive(disp);
  
  //waiting for semaphore held by task 3
  xSemaphoreTake(xMutex,portMAX_DELAY);
  while(1){
    // xSemaphoreTake(disp,portMAX_DELAY);
    Serial.print(F("T1"));
    // xSemaphoreGive(disp);
    vTaskDelay(3000/portTICK_PERIOD_MS);
  }
}
void task2(void *param){
  (void) param;
  // xSemaphoreTake(disp,portMAX_DELAY);
  Serial.print(F("T2e"));
  // xSemaphoreGive(disp);
  vTaskDelay(1000/portTICK_PERIOD_MS);
  //waiting for task 3 to release semaphore
  xSemaphoreTake(binarySem,portMAX_DELAY);
 
  while(1){
    // xSemaphoreTake(disp,portMAX_DELAY);
    Serial.print(F("T2"));
    // xSemaphoreGive(disp);
    vTaskDelay(3000/portTICK_PERIOD_MS);
  }
}
void task3(void *param){
  (void) param;
  int i;
  //take mutex so task 1 cant run
  xSemaphoreTake(xMutex,portMAX_DELAY);
  // xSemaphoreTake(disp,portMAX_DELAY);
  Serial.print("3mt");
  // xSemaphoreGive(disp);
  vTaskDelay(1000/portTICK_PERIOD_MS);

  for(i=1;;i++){
    // xSemaphoreTake(disp,portMAX_DELAY);
    // xSemaphoreGive(disp);
    if(i==2){
      // xSemaphoreTake(disp,portMAX_DELAY);
      Serial.print(F("sg"));
      // xSemaphoreGive(disp);
      //give semaphore to task 2
      xSemaphoreGive(binarySem);
      //task 2 starts running
    }
    if(i==4){
      Serial.print(F("tr"));
      //resume suspended task 1
      vTaskResume(taskHandle1);
    }
    if(i==7){
      // xSemaphoreTake(disp,portMAX_DELAY);
      Serial.print(F("mg"));
      // xSemaphoreGive(disp);
      //give mutex to task 1
      xSemaphoreGive(xMutex);
    }
    Serial.print("T3");
    if(i==10){
      Serial.print("bas hoagaya na");
      vTaskDelete(taskHandle1);
      vTaskDelete(taskHandle2);
      vTaskDelete(NULL);
    }
    vTaskDelay(3000/portTICK_PERIOD_MS);
  }
}
