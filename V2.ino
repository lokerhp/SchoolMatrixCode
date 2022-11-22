/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    switch(customKey){
      case '3':
        Serial.println("30 aan");
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
        break;
      case '#':
        Serial.println("Kruise Uit");
        break;
      case 'A':
        Serial.println("Pijl links aan");
        break;
      case 'B':
        Serial.println("Pijl rechts aan");
        break;
      case 'C':
        Serial.println("Kruis aan");
        break;
      default:
        Serial.println("Niet Bekend");
    }
  }
}
