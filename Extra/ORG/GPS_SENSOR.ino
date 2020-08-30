#include <SoftwareSerial.h>
#include <TinyGPS.h>
float lat = 27.2038,lon = 77.5011; // create variable for latitude and longitude object
SoftwareSerial gpsSerial(3,4);//rx,tx
TinyGPS gps; // create gps object

void gps_sensor(){
    while(gpsSerial.available()){ // check for gps data
      if(gps.encode(gpsSerial.read()))// encode gps data
      {
        gps.f_get_position(&lat,&lon); // get latitude and longitude
    // display position
        display.clearDisplay();
        display.setCursor(0,0);
        display.println(F("GPS location"));
        display.display();
    //Serial.print("Position: ");
    //Serial.print("Latitude:");
    //Serial.print(lat,6);
    //Serial.print(";");
    //Serial.print("Longitude:");
    //Serial.println(lon,6);
        display.print(F("LAT:"));
        display.println(lat);
        display.println(F("*N"));
        display.display();
    //Serial.print(lat);
    //Serial.print(" ");
   
        display.print(F("LON:"));
        display.print(lon);
        display.println("*E");
        display.display();
        delay(6000);
      }
    } 
}
