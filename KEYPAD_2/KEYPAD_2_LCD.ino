#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.init();
  lcd.home();
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
    lcd.setCursor(3, 0);
    lcd.print(key);
  }
}
