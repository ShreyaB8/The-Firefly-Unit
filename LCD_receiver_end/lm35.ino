int val;
int tempPin = 1;
void lm35()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000;
float cel = mv/10;
float farh = (cel*9)/5 + 32;

  lcd.setCursor(3,0);
  lcd.println("BODY TEMP= ");
  lcd.setCursor(3,1);
  lcd.print(cel);

  
/* uncomment this to get temperature in farenhite
Serial.print("TEMPRATURE = ");
Serial.print(farh);
Serial.print("*F");
Serial.println();


*/
}
