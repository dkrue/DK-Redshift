
#include <Encoder.h>
#include <LightDK.h>

//#define DEBUG
#define midiChannel 1
#define encoderButton 8

Encoder myEnc(1, 2);

// RGB LEDs (redPin, greenPin, bluePin) -note: red not on PWM this time
LightDK led = LightDK(12, 9, 10);

void setup() {
  pinMode(encoderButton, INPUT_PULLUP);
  
  #ifdef DEBUG
  Serial.begin(9600);
  #endif
}

long oldPosition  = -999;
int prgrm = 0;

void loop() {
  long newPosition = myEnc.read();

  // Reset to program 0 when encoder button is pressed
  if(digitalRead(encoderButton) == LOW) {
    #ifdef DEBUG
    Serial.println("Button pressed");
    #endif
    
    prgrm = 0;
    oldPosition = newPosition;
    
    // Send MIDI program value
    usbMIDI.sendProgramChange(prgrm, midiChannel);
    
    led.setColor(true, false, true);
    delay(200);
  }

  // Detect clockwise/counterclockwise step from quadrature encoder
  if (newPosition >= oldPosition + 4 || newPosition <= oldPosition - 4) {    
    if(newPosition >= oldPosition + 4 && prgrm < 127) {
      prgrm++;
    }
    if(newPosition <= oldPosition - 4 && prgrm > 0) {
      prgrm--;
    }

    oldPosition = newPosition;
    #ifdef DEBUG
    Serial.print("position ");
    Serial.println(newPosition);
    Serial.print("midi ");
    Serial.println(prgrm);
    #endif

    // Send MIDI program value
    usbMIDI.sendProgramChange(prgrm, midiChannel);

    led.setColor(true, false, true);
    delay(10); // too long of a delay interferes with encoder
  }

  // MIDI Controllers should discard incoming MIDI messages
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
  
  led.setColor(true, false, false);
}
