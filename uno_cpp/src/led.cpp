// Arduino Uno Built-in LED Blink Sketch (C++)
// LED ON for 5 seconds, LED OFF for 1 second

#include <Arduino.h>

const int LED_PIN = 13;  // Built-in LED pin on Arduino Uno

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Optional: Initialize Serial for debugging (9600 baud)
  Serial.begin(9600);
  Serial.println("Arduino LED Blink started!");
}

void loop() {
  // Turn LED ON for 5 seconds
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  delay(5000);  // 5 seconds
  
  // Turn LED OFF for 1 second
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  delay(1000);  // 1 second
}
