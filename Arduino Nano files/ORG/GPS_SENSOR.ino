#include <SoftwareSerial.h>
#include <TinyGPS.h>
float lat = 12.8224,lon = 80.0456; // create variable for latitude and longitude object
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
            display.print(F("LAT:"));
        display.println(lat);
        display.println(F("*N"));
        display.display();
     
        display.print(F("LON:"));
        display.print(lon);
        display.println("*E");
        display.display();
        delay(6000);
      }
    } 
display.println(F("GPS location"));
        display.display();
            display.print(F("LAT:"));
        display.println(lat);
        display.println(F("*N"));
        display.display();
     
        display.print(F("LON:"));
        display.print(lon);
        display.println("*E");
        display.display();
        delay(6000);
}
