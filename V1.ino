/*
 * NAAM: MATRIXBORD MEESTERPROEF 2022
 * VERSIE: 1
 * AUTEURS: NIEK, JOERI, DESMOND EN KAI
 * DATUM: 15 NOVEMBER 2022
 * 
 */
String incomingByte;
void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(2, HIGH);
}

// the loop function runs over and over again forever
void loop() {
    if (Serial.available() > 0) {
          incomingByte = Serial.readString();
          if(incomingByte == "ON"){
            digitalWrite(2, LOW);
            Serial.println("Ok");   
          } else if(incomingByte == "OFF"){
            digitalWrite(2, HIGH);
            Serial.println("Turned lamp off");
          } else {
            Serial.println("Command not found!");   
          }
    }
}
