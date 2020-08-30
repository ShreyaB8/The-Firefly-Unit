int led = 13;
int received = 0;
int i=0;


void setup() {
  Serial.begin(9600); 
  pinMode(led, OUTPUT);
}
 
void loop() {
  if (Serial.available() > 0) {
      digitalWrite(led, LOW);
received = Serial.read();
    //digitalWrite(led, HIGH);
   if (received =='b')
     {
    digitalWrite(led, HIGH);
    }
  } 
}

