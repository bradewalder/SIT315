// Pin assignments
const int motionSensorPin = 2;  // Digital input pin for the PIR motion sensor
const int ledPin = 13;          // Digital output pin for the LED

// Variables
volatile int motionState = LOW;  // Motion state (LOW: no motion, HIGH: motion detected)

void setup() {
  pinMode(motionSensorPin, INPUT);    // Set PIR motion sensor pin as input
  pinMode(ledPin, OUTPUT);            // Set LED pin as output
  Serial.begin(9600);                 // Initialize serial communication for monitoring

  attachInterrupt(digitalPinToInterrupt(motionSensorPin), handleMotionInterrupt, CHANGE);
}

void handleMotionInterrupt() {
  motionState = digitalRead(motionSensorPin);  // Read the motion sensor state

  if (motionState == HIGH) {
    digitalWrite(ledPin, HIGH);   // Turn on the LED if motion is detected
    Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW);    // Turn off the LED if no motion is detected
    Serial.println("No motion detected.");
  }
}

void loop() {
  // Other code or tasks can be performed here if needed
}