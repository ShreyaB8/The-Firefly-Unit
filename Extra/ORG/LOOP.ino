int value ; 

void loop() {
  ////////Lora comm/////////////////////////
  // send packet
  if(value == LOW )
  {
  LoRa.beginPacket();
  LoRa.print("100"); // code sheet
  LoRa.print(lat);
  LoRa.print("°N,");
  LoRa.print(lon);//gps location
  LoRa.print("°E");
  LoRa.endPacket();
  delay(2000);
  }
  ////////Xbee SOS button////////////////////
  
  value = digitalRead(7);
  if(value == LOW)
  {
    sos();
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

}
