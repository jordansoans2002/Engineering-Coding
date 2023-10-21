//simulated on wokwi controlled using blynk
//https://wokwi.com/projects/375094354316034049
#define BLYNK_TEMPLATE_ID "TMPL3zRR51aG_"
#define BLYNK_TEMPLATE_NAME "Traffic Signal"
#define BLYNK_AUTH_TOKEN "vVSXS7Px4mpY4MXPkJar_IoXFP3STrVV"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

char ssid[] = "Wokwi-GUEST";
char pass[] = "";
BlynkTimer timer;
#define RED 14
#define YELLOW 13
#define GREEN 12
int SW_R = 0;
int SW_Y = 0;
int SW_G = 0;
int t=0;


BLYNK_WRITE(V0)
{
  int SW_R = param.asInt();
  if(SW_R == 1)
    t=0;
}


BLYNK_WRITE(V1)
{
  int SW_Y = param.asInt();
  if(SW_Y == 1)
    t=10;
}


BLYNK_WRITE(V2)
{
  int SW_G = param.asInt();
  if(SW_G == 1)
    t=13;
   
}

BLYNK_WRITE(V3){
  int time = param.asInt();
  t = time * 10;
}


void setup()
{
  LCD.init();
  LCD.backlight();
  LCD.setCursor(0, 0);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}


void loop()
{
  Blynk.run();
  timer.run();
  delay(1000);
  t++;
  LCD.clear();
  LCD.setCursor(7,0);
  LCD.print(t);
  if(t<10 && SW_R != 1){
    LCD.setCursor(7,1);
    LCD.print("Stop");
    SW_R = 1;
    SW_Y = 0;
    SW_G = 0;
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    Blynk.virtualWrite(V0, 1);
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V3,0);
  } else if(t >= 10 && t<= 12 && SW_Y != 1){
    LCD.setCursor(7,1);
    LCD.print("Look");
    SW_R = 0;
    SW_Y = 1;
    SW_G = 0;
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V1, 1);
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V3,1);
  } else if(t > 12 && t < 20 && SW_G != 1){
    LCD.setCursor(7,1);
    LCD.print("GO!");
    SW_R = 0;
    SW_Y = 0;
    SW_G = 1;
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V2, 1);
    Blynk.virtualWrite(V3,1);
  } else if(t==20){
    t=0;
  }
}
