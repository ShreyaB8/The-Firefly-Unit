int received = 0;

void loop() {
   ///////Xbbee receiver/////////////
    if (Serial.available() > 0) {
     received = Serial.read();
  
     lcd.print("xbee activated");
     Serial.println("xbee activated");
     lcd.print(received);
     delay(1000);
}


  bmp_180();
  delay(2000);
  
  lcd.clear();
  gps_sensor();
    delay(2000);

  lcd.clear();
  pulse_sensor();
    delay(2000);

  lcd.clear();
  mq2();
     delay(2000);

  lcd.clear();
   MQ135();
    delay(2000);

  lcd.clear();
    lm35();
      delay(2000);

}
