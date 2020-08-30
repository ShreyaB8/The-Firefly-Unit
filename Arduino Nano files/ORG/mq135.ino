
int airquality = 0;

void MQ135()
{
  
  int sensorValue = analogRead(A2);
  
  display.setCursor(0,0);
  display.println(F("Air Quality: "));
  display.display();
  //Serial.print("Air Quality = ");
  //Serial.print(sensorValue); 
  display.print(sensorValue);
  display.print(F("ppm"));
  display.display();
  //Serial.print("*ppm");
  //Serial.println();



}
