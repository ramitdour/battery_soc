
#include <Arduino.h>
#include <BatterySocData.h>     // Contains Configurable parameters

#include <Wire.h>   //  I2C communication SDA,SCL
#include <Ticker.h> //  Tickers which can call repeating functions. Replaces delay() with non-blocking functions

#include <Adafruit_ADS1X15.h>   //  ADS1115 16-bit ADC
#include <Adafruit_INA219.h>    //  INA218  12-bit current sensing IC using shunt

// #include <ArduinoJson.h>     //  Easy handling of JSON data in C/C++


#ifndef BatterySoc_h
#define BatterySoc_h



/*Setup LCD display*/
void setup_lcd_i2c();

/*Setup 7 Segment display*/
void setup_7seg_i2c();

/*Setup push buttons*/
void setup_push_buttons();

/*Setup Analog Read : For V-bat (64V)*/
void setup_analog_read();

/*Setup ADS1115*/
void setup_ads1115();

/*Setup INA219*/
void setup_ina219();

/*Only Execute once while power on*/
void setup();


/*Infinite loop*/
void loop();



#endif