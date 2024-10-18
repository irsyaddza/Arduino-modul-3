int buttonPin = 7;   // Pin connected to the push button
int buzzerPin = 3;   // Pin connected to the buzzer (PWM pin)
int buttonState = 0; // Variable to store button state

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Enable internal pull-up resistor
  pinMode(buzzerPin, OUTPUT);        // Set buzzer pin as output
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Read the state of the button

  // Check if the button is pressed (LOW because of pull-up resistor)
  if (buttonState == LOW) {
    // When the button is pressed, increase buzzer intensity
    for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
      analogWrite(buzzerPin, fadeValue);  // Set the buzzer intensity (PWM)
      delay(30);  // Short delay to create the fading effect
    }

    // Optionally, add a decrease effect after the increase
    for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
      analogWrite(buzzerPin, fadeValue);  // Decrease the buzzer intensity
      delay(30);  // Short delay to create the fading effect
    }
  } else {
    // If the button is not pressed, turn the buzzer off
    analogWrite(buzzerPin, 0);  // Ensure the buzzer is off
  }
}