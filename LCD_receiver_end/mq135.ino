
int airquality = 0;

void MQ135()
{
  
  int sensorValue = analogRead(A2);
  
  lcd.setCursor(3,0);
  lcd.print("Air Quality = ");
  //Serial.print("Air Quality = ");
  //Serial.print(sensorValue);
  lcd.setCursor(3,1);
  lcd.print(sensorValue);
  lcd.print("PPM");
  //Serial.print("*PPM");
  //Serial.println();
  if(sensorValue> 300)
{ sos();
  }

}
