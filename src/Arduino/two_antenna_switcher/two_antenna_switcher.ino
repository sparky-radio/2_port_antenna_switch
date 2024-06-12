#include <hd44780.h>

/*Import following Libraries*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define ANTENNA_RELAY_1  2 // The Arduino Nano pin connected to the IN1 pin of relay module
#define ANTENNA_RELAY_2  3 // The Arduino Nano pin connected to the IN2 pin of relay module

#define DELAY 3000

void setup() {
  Serial.begin(9600);
  init_relays();
  init_display();
}

void init_relays() {
  // initialize digital pin as an output.
  pinMode(ANTENNA_RELAY_1, OUTPUT);
  pinMode(ANTENNA_RELAY_2, OUTPUT);
}

void init_display() {
  lcd.init();
  lcd.clear();                     
  lcd.backlight();

  // lcd.setCursor(0,0);
  // Serial.println("---");
  // write_display_1("Testing Antenna");
  // Serial.println("---");   
}

void write_display(char * line1, char * line2) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(line1);
  lcd.setCursor(0,1);
  lcd.print(line2);
}

void write_display_1(char * txt)
{
  lcd.setCursor(0,0);
  lcd.print(txt);
}

void write_display_2(char * txt)
{
  lcd.setCursor(0,1);
  lcd.print("               ");
  lcd.setCursor(0,1);
  lcd.print(txt);
}

void loop() {
  delay(DELAY);
  write_display("Testing Antenna", "All On");
  digitalWrite(ANTENNA_RELAY_1, HIGH);
  digitalWrite(ANTENNA_RELAY_2, HIGH);
  
  delay(DELAY);
  write_display("Testing Antenna", "All Off");
  digitalWrite(ANTENNA_RELAY_1, LOW);
  digitalWrite(ANTENNA_RELAY_2, LOW);
  
  delay(DELAY);
  write_display("Testing Antenna", "1 On - 2 Off");
  digitalWrite(ANTENNA_RELAY_1, HIGH);
  digitalWrite(ANTENNA_RELAY_2, LOW);
  
  delay(DELAY);
  write_display("Testing Antenna", "1 Off - 2 On");
  digitalWrite(ANTENNA_RELAY_1, LOW);
  digitalWrite(ANTENNA_RELAY_2, HIGH);
  
  
}
