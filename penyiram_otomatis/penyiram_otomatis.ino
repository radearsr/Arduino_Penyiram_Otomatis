//Code By RADEARSR

/*
 * Pin LCD I2C    ||  Pin Arduino    
 *    GND               Pin GND
 *    VCC               Pin 5V
 *    SDA               Pin A4
 *    SCL               Pin A5
*/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int sensorPin = A0;  // pin sensor
int relay = 7;     // Pin Relay 
 
void setup() {  
  lcd.init();
  lcd.backlight();
  pinMode(powerPin, OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(powerPin, LOW);
  Serial.begin(9600);
}
 
void loop() {
  lcd.setCursor(0,0);
  int value = analogRead(sensorPin);
  int lembab = 1023 - value;
  lcd.print("Kelembaban: ");
  lcd.print(lembab);
  

//  Jika Kelembaban Tanah Lebih dari 750 Maka Pompa Air Mati
  if( lembab > 700 && lembab < 1000 ){

    lcd.setCursor(0,1); 
    lcd.print("===Tanah Oke===");
    delay(500);
    lcd.print("");
    digitalWrite(relay, HIGH);
    delay(2000);
    
  }
//  Jika Kelembaban Tanah Kurang dari 750
  else if( lembab < 689 ){
    
   lcd.setCursor(0,1);
   lcd.print("===Siram Tanah===");
   lcd.print("");
   digitalWrite(relay, LOW);
   delay(2000);
   
  }
}
