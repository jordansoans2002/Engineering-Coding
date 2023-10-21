//simulated using Wokwi and mymqtt android app
//https://wokwi.com/projects/379177050008993793
#include <WiFi.h>
#include "PubSubClient.h"
#include <LiquidCrystal_I2C.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqttServer = "test.mosquitto.org"; //can also put ip address
int port = 1883;
String stMac;
char mac[50];
char clientId[50];

WiFiClient espClient;
PubSubClient client(espClient);
LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

#define RED 14
#define YELLOW 13
#define GREEN 12
int t=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  randomSeed(analogRead(0));

  delay(10);
  Serial.println("Hello, ESP32!");
  Serial.println("Connecting to ");
  Serial.println(ssid);

  wifiConnect();
  Serial.println("\nWifi Connected");
  
  client.setServer(mqttServer,port);
  client.setCallback(callback);

  LCD.init();
  LCD.backlight();
  LCD.setCursor(0, 0);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void wifiConnect(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
}

void mqttReconnect() {
  while(!client.connected()){
    Serial.println("connecting to MQTT");
    long r = random(1000);
    sprintf(clientId,"clientId-%ld",r);
    if(client.connect(clientId)){
      Serial.print(clientId);
      Serial.print(" connected");
      Serial.println();
      client.subscribe("signal/time");
      client.subscribe("signal/color");
      client.publish("signal/status","Signal is online");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* message, unsigned int length){
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String msg;
  char arr[length];

  for(int i=0;i<length;i++){
    Serial.print((char)message[i]);
    msg+=(char)message[i];
    arr[i]=(char)message[i];
  }
  Serial.println();

  if(String(topic) == "signal/time"){
    t = atoi(arr);
    if(t>20)
      t=t%20;
  } else if(String(topic) == "signal/color"){
    if(msg == "green"){
      client.publish("signal/status","GO");
      digitalWrite(GREEN, HIGH);
      digitalWrite(YELLOW,LOW);
      digitalWrite(RED,LOW);
    } else{
      client.publish("signal/status","Stop");
      digitalWrite(RED, HIGH);
      digitalWrite(YELLOW,LOW);
      digitalWrite(GREEN,LOW);
    }
  } else
    Serial.println("error message");
}
void loop() {
  delay(1000); // this speeds up the simulation
  if(!client.connected()){
    mqttReconnect();
  }
  client.loop();

  LCD.clear();
  LCD.setCursor(7,0);
  LCD.print(t);
  t = (t<20)?++t:1;
  if(t==1){
    client.publish("signal/status","GO");
    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW,LOW);
    digitalWrite(RED,LOW);
  } else if(t==9){
    client.publish("signal/status","Look");
    digitalWrite(YELLOW, HIGH);
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,LOW);
  } else if(t==11){
    client.publish("signal/status","Stop");
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW,LOW);
    digitalWrite(GREEN,LOW);
  }
}
