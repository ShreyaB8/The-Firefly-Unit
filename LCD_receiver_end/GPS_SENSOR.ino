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
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("GPS Signal");
    //Serial.print("Position: ");
    //Serial.print("Latitude:");
    //Serial.print(lat,6);
    //Serial.print(";");
    //Serial.print("Longitude:");
    //Serial.println(lon,6);
        lcd.setCursor(3,0);
        lcd.print("LAT:");
        lcd.print(lat);
        lcd.print("*N");
    //Serial.print(lat);
    //Serial.print(" ");
   
        lcd.setCursor(3,1);
        lcd.print("LON:");
        lcd.print(lon);
        lcd.print("*E");
   
      }
    }
 
  String latitude = String(lat,6);
    String longitude = String(lon,6);

        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("GPS Signal");

        lcd.setCursor(3,1);
        lcd.print("LAT:");
        lcd.print(lat);
        lcd.print("*N");

        lcd.setCursor(3,2);
        lcd.print("LON:");
        lcd.print(lon);
        lcd.print("*E");
    
    
  //lcd.print(latitude+"°N;"+longitude "°E");
  
 
}
