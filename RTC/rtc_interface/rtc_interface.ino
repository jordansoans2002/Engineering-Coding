#include <Wire.h>
#include <DS1307RTC.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);

DS1307RTC rtc;
tmElements_t tm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //set baud rate
  lcd.init();

  tm.Year = CalendarYrToTm(2023);
  tm.Month = 3;
  tm.Day = 9;
  tm.Hour = 12;
  tm.Minute = 30;
  tm.Second = 0;
  RTC.write(tm);
 
//  rtc.begin(); //init rtc
//  //rtc.set(0,30,11,9,3,2023); //11:30:00 09-03-2023  
//  rtc.set(); //11:30:00 09-03-2023  
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t sec,min,hour,day,month;
  uint16_t year;

  RTC.read(tm);
  //rtc.get(&sec, &min, &hour, &day, &month, &year);
  
//serial output
  Serial.print("nTime: ");
  Serial.print(tm.Hour);
  Serial.print(":");
  Serial.print(tm.Minute);
  Serial.print(":");
  Serial.print(tm.Second);
  Serial.print("nDate: ");
  Serial.print(tm.Day);
  Serial.print(".");
  Serial.print(tm.Month);
  Serial.print(".");
  Serial.print(tmYearToCalendar(tm.Year));

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Date: ");
  lcd.print(tm.Day);
  lcd.print("/");
  lcd.print(tm.Month);
  lcd.print("/");
  lcd.print(tmYearToCalendar(tm.Year));
  lcd.setCursor(1, 1);
  lcd.print("Time:");
  lcd.print(tm.Hour);
  lcd.print(":");
  lcd.print(tm.Minute);
  lcd.print(":");
  lcd.print(tm.Second);
  delay(1000);
}
