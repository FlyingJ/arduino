/*
  Love Meter
  Thermistor measures temperature and starts lighting LEDs and stuff.
*/

const int sensorPin = A0;
const float baselineTemp = 27.0;

void setup ()
{
  Serial.begin(9600); // open a serial port
  
  for(int pinNumber = 2; pinNumber < 5; pinNumber++) // loop through pins 2, 3, 4
  {
    pinMode(pinNumber, OUTPUT); // set the pins for OUTPUT
    digitalWrite(pinNumber, LOW); // set pins to LOW voltage (turn off lights)
  }
}

void loop ()
{
  int sensorVal = analogRead(sensorPin); // read thermistor value off pin A0
  
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  
  float voltage = (sensorVal/1024.0) * 5.0; // normalize thermistor value (0-1024), then scale the total voltage (5V)
  
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  Serial.print(", Degrees C: ");
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);
  
  if (temperature < baselineTemp)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baselineTemp + 2 &&
           temperature < baselineTemp + 4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baselineTemp + 4 &&
           temperature < baselineTemp + 6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baselineTemp + 6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  
  delay(1);
  
}
