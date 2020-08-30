#include <SFE_BMP180.h>
#include <Wire.h>

// You will need to create an SFE_BMP180 object, here called "pressure":

SFE_BMP180 pressure; //SFE_BMP180 is the pressure sensor library for arduino

#define ALTITUDE 37.0 // Altitude of SparkFun's HQ in Boulder, CO. in meters



void bmp_180()
{
  char status;
  double T,P,p0,a;

  // Loop here getting pressure readings every 10 seconds.

  // If you want sea-level-compensated pressure, as used in weather reports,
  // you will need to know the altitude at which your measurements are taken.
  // We're using a constant called ALTITUDE in this sketch:
  
 /* Serial.println();
  Serial.print("provided altitude: ");
  Serial.print(ALTITUDE,0);
  Serial.print(" meters, ");
  Serial.print(ALTITUDE*3.28084,0);
  Serial.println("feet");*/

  /*lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("provided altitude: ");
  lcd.setCursor(3,1);
  lcd.print(ALTITUDE,0);
  lcd.print(" meters, ");
  lcd.setCursor(3,2);
  lcd.print(ALTITUDE*3.28084,0);
  lcd.println("feet");
  delay(2000);*/
  // If you want to measure altitude, and not pressure, you will instead need
  // to provide a known baseline pressure. This is shown at the end of the sketch.

  // You must first get a temperature measurement to perform a pressure reading.
  
  // Start a temperature measurement:
  // If request is successful, the number of ms to wait is returned.
  // If request is unsuccessful, 0 is returned.

  status = pressure.startTemperature();
  if (status != 0)
  {
    // Wait for the measurement to complete:
    delay(status);

    // Retrieve the completed temperature measurement:
    // Note that the measurement is stored in the variable T.
    // Function returns 1 if successful, 0 if failure.

    status = pressure.getTemperature(T);
    if (status != 0)
    {
      // Print out the measurement:
      /*Serial.print("temperature: ");
      Serial.print(T,2);
      Serial.print(" deg C, ");
      Serial.print((9.0/5.0)*T+32.0,2);
      Serial.println(" deg F");*/
      
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("temperature: ");
       lcd.setCursor(3,1);
      lcd.print(T,2);
      lcd.print(" °C ");
       lcd.setCursor(3,2);
      //lcd.print((9.0/5.0)*T+32.0,2);
      //lcd.println(" deg F");
      delay(2000);
      // Start a pressure measurement:
      // The parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
      // If request is successful, the number of ms to wait is returned.
      // If request is unsuccessful, 0 is returned.

      status = pressure.startPressure(3);
      if (status != 0)
      {
        // Wait for the measurement to complete:
        delay(status);

        // Retrieve the completed pressure measurement:
        // Note that the measurement is stored in the variable P.
        // Note also that the function requires the previous temperature measurement (T).
        // (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
        // Function returns 1 if successful, 0 if failure.

        status = pressure.getPressure(P,T);
        if (status != 0)
        {
          // Print out the measurement:
         /* Serial.print("absolute pressure: ");
          Serial.print(P,2);
          Serial.print(" mb, ");
          Serial.print(P*0.0295333727,2);
          Serial.println(" inHg");*/

          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("absolute pressure: ");
          lcd.setCursor(3,1);
          //lcd.print(P,2);
          //lcd.print(" mb, ");
          //lcd.setCursor(3,1);
          lcd.print(P*0.0295333727,2);
          lcd.println(" inHg");
            delay(2000);


          // The pressure sensor returns abolute pressure, which varies with altitude.
          // To remove the effects of altitude, use the sealevel function and your current altitude.
          // This number is commonly used in weather reports.
          // Parameters: P = absolute pressure in mb, ALTITUDE = current altitude in m.
          // Result: p0 = sea-level compensated pressure in mb

          p0 = pressure.sealevel(P,ALTITUDE); // we're at 1655 meters (Boulder, CO)
          /*Serial.print("relative (sea-level) pressure: ");
          Serial.print(p0,2);
          Serial.print(" mb, ");
          Serial.print(p0*0.0295333727,2);
          Serial.println(" inHg");*/

          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("relative pressure: "); //sealevel
          //lcd.print(p0,2);
          //lcd.print(" mb, ");
          lcd.setCursor(3,1);
          lcd.print(p0*0.0295333727,2);
          lcd.println(" inHg");
            delay(2000);


          // On the other hand, if you want to determine your altitude from the pressure reading,
          // use the altitude function along with a baseline pressure (sea-level or other).
          // Parameters: P = absolute pressure in mb, p0 = baseline pressure in mb.
          // Result: a = altitude in m.

          a = pressure.altitude(P,p0);
         /* Serial.print("computed altitude: ");
          Serial.print(a,0);
          Serial.print(" meters, ");
          Serial.print(a*3.28084,0);
          Serial.println(" feet");*/

          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("computed altitude:");
          lcd.setCursor(3,1);
          lcd.print(a,0);
          lcd.print(" M ");
         // lcd.setCursor(3,2);
        //  lcd.print(a*3.28084,0);
         // lcd.println(" feet");
            delay(2000);

        }
        else lcd.print("error retrieving pressure measurement\n");
      }
      else lcd.print("error starting pressure measurement\n");
    }
    else lcd.print("error retrieving temperature measurement\n");
  }
  else lcd.print("error starting temperature measurement\n");

}
