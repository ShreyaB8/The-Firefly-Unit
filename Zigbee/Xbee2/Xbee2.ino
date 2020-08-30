int led = 13;
int received = 0;
int i;
void setup() {
  Serial.begin(9600); 
  pinMode(led, OUTPUT);
}
 
void loop() {
  digitalWrite(led, HIGH);
  if (Serial.available() > 0) {
received = Serial.read();
  
    if (received == 'a'){
    digitalWrite(led, HIGH);
    delay(2000);
    digitalWrite(led, LOW);
    }
     else if (received == 100){
    digitalWrite(led, LOW);
  } 
}
}
