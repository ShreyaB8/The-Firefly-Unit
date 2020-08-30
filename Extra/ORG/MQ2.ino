int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A3;
// Your threshold value
int sensorThres = 450;



void mq2() {
  int analogSensor = analogRead(smokeA0);
display.setCursor(0,0);
  display.println(F("levels of toxic gas in air ")); //subject to changes
  display.print(analogSensor);
  display.display();
  delay(6000);
  
  
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
}
