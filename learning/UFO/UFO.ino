// UFO
//
// No button: green LED, no red LEDs
// Button: red LEDs, no green LED
//

// initial state of the switch is open, low, 0
int switchState = 0;

void setup()
{
  // this is for checking the switch
  pinMode(2, INPUT);
  // this is for green LED
  pinMode(3, OUTPUT);
  // these are for the red LEDs
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  // check state of switch
  switchState = digitalRead(2);
  
  // light the LEDs appropriately (see description above)
  if (switchState == LOW)
  {
    // button is not pressed
    digitalWrite(3, HIGH); // green LED on
    digitalWrite(4, LOW);  // red LED off
    digitalWrite(5, LOW);  // red LED off
  }
  else
  {
    // button is pressed
    digitalWrite(3, LOW);  // green LED off
    digitalWrite(4, LOW);  // red LED still off
    digitalWrite(5, HIGH); // red LED on
    // wait for it...
    delay(250); // 250 millisecond pause
    // flip the red LEDs
    digitalWrite(4, HIGH); // red LED on
    digitalWrite(5, LOW);  // red LED off
    // wait for it again...
    delay(250); // another 250 millisecond pause
  } // done flipping lights. go to top and read again.
} // go back to beginning of loop
