int received =0;
int value=0;
int value2=0;
void loop() {
  //////sos button/////////
   value = digitalRead(7);
   if(value == HIGH)
  {
    delay(2000);
    if(value == HIGH)
  {
      sos();
  }
  }
  /////////delete node button
value2 = digitalRead(6);
   if(value == HIGH)
  {
    delay(2000);
    if(value == HIGH)
  {
      del_node();
  }
  }
  
  ///////Xbbee receiver/////////////
    if (Serial.available() > 0) {
     received = Serial.read();
   lcd.print(received);
}
  //////////OLED//////////////////
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0); 
 
  
  bmp_180();
  delay(6000);
  
  display.clearDisplay();
  gps_sensor();
    delay(6000);

  display.clearDisplay();
  pulse_sensor();
    delay(6000);

  display.clearDisplay();
  MQ135();
    delay(6000);

  display.clearDisplay();
    lm35();
      delay(6000);

       display.clearDisplay();
    mq2();
      delay(6000);

      

}
