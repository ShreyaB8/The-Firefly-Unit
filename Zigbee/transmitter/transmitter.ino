
//const int potPin = A1; //Pot at Arduino A0 pin 
//Variables:
int value ; //Value from pot

void setup() {
  //Start the serial communication
  Serial.begin(9600); //Baud rate must be the same as is on xBee module
  pinMode(7,INPUT);
}

void loop() {
  
  //Read the analog value from pot and store it to "value" variable
  value = digitalRead(7);
  //Map the analog value to pwm value
  //value = map (value, 0, 1023, 0, 255);
  //Send the message:
  //Serial.print('<');  //Starting symbol
  if(value == LOW)
  {
    Serial.println(100);//Value from 0 to 255
  }
  //Serial.println('>');//Ending symbol
}
  
