#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

LiquidCrystal lcd(12, 11, 9, 8, 7, 6);
char buffer[16];
int charsRead;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);       
    lcd.begin(16, 2);
    lcd.print("Welcome!");
    delay(3000);
    lcd.clear();
}
void loop() {
 
if(mySerial.available() > 0){

charsRead = mySerial.readBytesUntil('\n', buffer, sizeof(buffer)-1);
lcd.clear();
buffer[charsRead] = '\0';

lcd.print(buffer);

delay(4000);

}
}


