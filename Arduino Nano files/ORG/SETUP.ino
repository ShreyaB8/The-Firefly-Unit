void setup() {
  /////////////Xbee//////////////
   Serial.begin(9600); //Baud rate must be the same as is on xBee module
  pinMode(7,INPUT);
  ///////////////delete node//////////////////
    pinMode(6,INPUT);

//////////////////lcd//////////////////////
Serial.begin(9600);
   if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println("Fail");
    Serial.println(F("SSD1306 allocation failed"));
    
    for(;;); // Don't proceed, loop forever
  }
  else Serial.println("Oled init successful");


  ///////////////BMP180//////////////////
  
  Serial.println("REBOOT");

  // Initialize the sensor (it is important to get calibration values stored on the device).

  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    // Oops, something went wrong, this is usually a connection problem,
    // see the comments at the top of this sketch for the proper connections.
    display.clearDisplay();
    display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println(F("BMP180 init fail"));
    display.display();
    Serial.println("BMP180 init fail\n\n");
    while(1); // Pause forever.
  }

  /////////////////////gps sensor/////////////
  Serial.begin(9600); // connect serial
//Serial.println("The GPS Received Signal:");
gpsSerial.begin(9600); // connect gps sensor


////////////////////////mq135/////////////////
  Serial.begin(9600);

////////////////////PULSE SENSOR///////////////
Serial.begin(9600); // For Serial Monitor

// Configure the PulseSensor object, by assigning our variables to it.
pulseSensor.analogInput(PulseWire);
pulseSensor.blinkOnPulse(LED13); //auto-magically blink Arduino's LED with heartbeat.
pulseSensor.setThreshold(Threshold);

// Double-check the "pulseSensor" object was created and "began" seeing a signal.
if (pulseSensor.begin()) {
//Serial.println("We created a pulseSensor Object !"); //This prints one time at Arduino power-up, or on Arduino reset.
display.setCursor(0,0);
display.print(F(" Heart Rate Monitor"));
display.display();

}

////////////mq2//////////////////////////////////////
pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);

  ///////////lm35///////////////////////////////////
  Serial.begin(9600);


}
