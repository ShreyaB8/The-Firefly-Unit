void setup() {
  /////////xbee///////////
    Serial.begin(9600); 
  //pinMode(led, OUTPUT);
//////////////////lcd//////////////////////


  lcd.begin();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();

  ///////////////BMP180//////////////////
  Serial.begin(9600);
  Serial.println("REBOOT");

  // Initialize the sensor (it is important to get calibration values stored on the device).

  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    // Oops, something went wrong, this is usually a connection problem,
    // see the comments at the top of this sketch for the proper connections.

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
lcd.setCursor(0,0);
lcd.print(" Heart Rate Monitor");

}

////////////mq2//////////////////////////////////////
  Serial.begin(9600); //Initialize serial port - 9600 bps



  ///////////lm35///////////////////////////////////
  Serial.begin(9600);


}
