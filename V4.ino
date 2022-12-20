/* @file V3.ino
|| @version 0.3
|| @author Niek, Desmond, Kai, Joeri
||
|| @description
|| | V3 of our matrixcode
|| #
|| @copyright Alexander Brevig
*/

#include <Keypad.h>

//variables for our keypad
const byte ROWS = 4;
const byte COLS = 4;
char keyTable[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //LTR -> ROW PINS
byte colPins[COLS] = {6, 7, 8, 9};//LTR -> COL PINS

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(keyTable), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode(10, OUTPUT); //Relais 1
  pinMode(11, OUTPUT); //Relais 2
  pinMode(12, OUTPUT); //Relais 3
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    switch(customKey){
      case '3':
        Serial.println("30 Aan");
        break;
      case '4':
        Serial.println("50 aan");
        digitalWrite(10, LOW);
        break;
      case '5':
        Serial.println("60 aan");
        digitalWrite(11, LOW);
        break;
      case '6':
        Serial.println("70 aan");
        digitalWrite(12, LOW);
        break;
      case '*':
        Serial.println("Cijfers Uit");
        break;
      case 'A':
        digitalWrite(10, HIGH);
        Serial.println("Kruizen Uit");
        break;
      case 'B':
        Serial.println("Pijl links aan");
        digitalWrite(11, HIGH);
        break;
      case 'C':
        Serial.println("Pijl rechts aan");
        digitalWrite(12, HIGH);
        break;
      default:
        Serial.println("Niet Bekend");
    }
  }
}
