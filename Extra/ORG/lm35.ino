int val;
int tempPin = 1;
void lm35()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000;
float cel = mv/10;
float farh = (cel*9)/5 + 32;

/*Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();*/

//temperature in celcius


  display.setCursor(0,0);
  display.println(F("TEMPERATURE = "));
  display.print(cel);
  display.display();
  
  
/* uncomment this to get temperature in farenhite
Serial.print("TEMPRATURE = ");
Serial.print(farh);
Serial.print("*F");
Serial.println();


*/
}
