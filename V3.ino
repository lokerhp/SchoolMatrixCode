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
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    switch(customKey){
      case '3':
        Serial.println("30 Aan");
        digitalWrite(10, HIGH);
        break;
      case '5':
        Serial.println("50 aan");
        break;
      case '6':
        Serial.println("60 aan");
        break;
      case '7':
        Serial.println("70 aan");
        break;
      case '*':
        Serial.println("Cijfers Uit");
        digitalWrite(11, LOW);
        break;
      case '#':
        digitalWrite(10, LOW);
        Serial.println("Kruizen Uit");
        break;
      case 'A':
        Serial.println("Pijl links aan");
        break;
      case 'B':
        Serial.println("Pijl rechts aan");
        break;
      case 'C':
        Serial.println("Kruis aan");
        digitalWrite(11, HIGH);
        break;
      default:
        Serial.println("Niet Bekend");
    }
  }
}
