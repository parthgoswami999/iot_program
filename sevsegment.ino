#include "SevSeg.h"

SevSeg s;
byte CommonPins[] = {};
byte SegPin[] = {2, 3, 4, 5, 6, 7, 8};

// Flag to stop the loop once the condition is met
bool stopCounting = false;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize the 7-segment display
  s.begin(COMMON_CATHODE, 1, CommonPins, SegPin, 1);
}

void loop() {
  // If counting hasn't stopped, continue counting
  if (!stopCounting) {
    for (int i = 0; i <= 9; i++) {
      s.setNumber(i);
      s.refreshDisplay();
      delay(1000); // Delay 1 second between numbers
      Serial.println(i);

      // When the number reaches 9, print "Hello" to serial and stop counting
      if (i == 9) {
        Serial.println("Hello");
        stopCounting = true; // Set flag to stop further counting
        break; // Exit the for loop
      }
    }
  }

  // Keep displaying 9 without restarting the count
  if (stopCounting) {
    s.setNumber(9); // Keep 9 on the display
    s.refreshDisplay(); // Keep refreshing the display to maintain 9
    delay(1000); // Small delay to ensure smooth display
  }
}
