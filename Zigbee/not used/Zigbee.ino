#include <SoftwareSerial.h>
#define rxPin 2
#define txPin 3
#define ledPin 13
SoftwareSerial xbee =  SoftwareSerial(rxPin, txPin);
void setup(){
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 xbee.begin(9600);
}

void loop(){
 xbee.print('A');
 delay(100);
}
