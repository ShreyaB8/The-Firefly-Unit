#define USE_ARDUINO_INTERRUPTS true // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h> // Includes the PulseSensorPlayground Library.


// Variables
const int PulseWire = 0; // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED13 = 13; // The on-board Arduino LED, close to PIN 13.
int Threshold = 550; // Determine which Signal to "count as a beat" and which to ignore.
// Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
// Otherwise leave the default "550" value.

PulseSensorPlayground pulseSensor; // Creates an instance of the PulseSensorPlayground object called "pulseSensor"

void pulse_sensor() {

int myBPM = pulseSensor.getBeatsPerMinute() - 150; // Calls function on our pulseSensor object that returns BPM as an "int".
// "myBPM" hold this BPM value now.
if (pulseSensor.sawStartOfBeat()) { // Constantly test to see if "a beat happened".
if(myBPM<200 || myBPM>60)
{/*Serial.println("♥ A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
Serial.print("BPM: "); // Print phrase "BPM: "
Serial.println(myBPM); // Print the value inside of myBPM.*/
display.setCursor(0,0);
display.print(F("BPM: ")); // Print phrase "BPM: "
display.print(myBPM);
display.display();
delay(6000);
}
else if((myBPM<50 && myBPM>20) || myBPM>200)
{
  display.print(F("EMERGENCY HEALTH CONDITION"));
  display.display();
  delay(6000);
//Serial.print("EMERGENCY HEALTH CONDITION");
sos();
  }
else
{
  display.print(F("Flat line condition"));
  display.display();
  delay(6000);
//Serial.print("Flat line condition");
myBPM=0;
sos();
}
}
 // considered best practice in a simple sketch.
}
