#include <Wire.h>
#include <DS1307RTC.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);

DS1307RTC rtc;
tmElements_t tm;

void setup() {
  lcd.init();

//set the date and time
  tm.Year = CalendarYrToTm(2023);
  tm.Month = 3;
  tm.Day = 9;
  tm.Hour = 12;
  tm.Minute = 30;
  tm.Second = 0;
//write date and time to RTC
  RTC.write(tm);
}

void loop() {
//read date and time from RTC
  RTC.read(tm);

//write to LCD
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
