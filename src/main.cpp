#include <Arduino.h>

#include <BatterySoc.h>


Adafruit_INA219 ina219;
Adafruit_ADS1115 ads;


void setup()
{

#ifdef DEBUG_CODE

  // Setup serial
  Serial.begin(SERIAL_BAUD_RATE);
  delay(1000);
  Serial.setDebugOutput(true);
  delay(1000);

#endif

  // // Setup push buttons
  // setup_push_buttons();

  // //  Setup Analog Read : For V-bat (64V) 
  // setup_analog_read();

  // //  Setup ADS1115
  // setup_ads1115();


  // //  Setup LCD display
  // setup_lcd_i2c();

  // //  Setup 7 Segment display
  // setup_7seg_i2c();

  
}

void loop()
{
  // print_to_serial();
}
