/*
  SOS
  LED blinks out SOS in Morse Code 
*/
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// basic unit of time .25s
int pause = 250;

// is function for blinking SOS
void sos()
{
  // first letter is S ...
  digitalWrite(led, HIGH); // led on
  delay(pause);             // leave led on for 0.25s
  digitalWrite(led, LOW);  // led off
  delay(pause);             // leave led off for 0.25s
  digitalWrite(led, HIGH); // led on
  delay(pause);
  digitalWrite(led, LOW);
  delay(pause);
  digitalWrite(led, HIGH);
  delay(pause);
  digitalWrite(led, LOW);
  delay(2 * pause);
  // second letter is O ---
  digitalWrite(led, HIGH);
  delay(3 * pause);
  digitalWrite(led, LOW);
  delay(pause);
  digitalWrite(led, HIGH);
  delay(3 * pause);
  digitalWrite(led, LOW);
  delay(pause);
  digitalWrite(led, HIGH);
  delay(3 * pause);
  digitalWrite(led, LOW);
  delay(2 * pause);
  // third letter is S ...
  digitalWrite(led, HIGH);
  delay(pause);
  digitalWrite(led, LOW);
  delay(pause);
  digitalWrite(led, HIGH);
  delay(pause);
  digitalWrite(led, LOW);
  delay(pause);
  digitalWrite(led, HIGH);
  delay(pause);
  digitalWrite(led, LOW);
  delay(4 * pause);
}

// the loop routine runs over and over again forever:
void loop() {
  sos(); // send for help
}
