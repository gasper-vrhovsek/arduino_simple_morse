/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/


int time_unit = 300;

int short_unit = time_unit;
int long_unit = 3 * time_unit;
int gap = time_unit;
int letter_gap = long_unit;
int word_gap = 7 * time_unit;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void morseCharacter(int character) {
  if (character == 'S' || character == 's') {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(short_unit);
    digitalWrite(LED_BUILTIN, LOW);
    delay(gap);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(short_unit);
    digitalWrite(LED_BUILTIN, LOW);
    delay(gap);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(short_unit);
    digitalWrite(LED_BUILTIN, LOW);
  }

  if (character == 'O' || character == 'o') {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(long_unit);
    digitalWrite(LED_BUILTIN, LOW);
    delay(gap);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(long_unit);
    digitalWrite(LED_BUILTIN, LOW);
    delay(gap);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(long_unit);
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(letter_gap);
}

void morseCode(String toPrint) {
  int stringLength = toPrint.length();

  for (int i=0; i < stringLength; i++) {
    // if space then word_gap!
    if (toPrint.charAt(i) == ' ') {
      delay(word_gap);  
    }

    //if not space, print character
    morseCharacter(toPrint.charAt(i));    
  }
}

// the loop function runs over and over again forever
void loop() {
  morseCode("SOS");
  delay(5000);  
  
}
