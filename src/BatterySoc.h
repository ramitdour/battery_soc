
#include <Arduino.h>


#ifndef BatterySoc_h
#define BatterySoc_h

#include <BatterySocData.h>

#include <Wire.h>

#include <Adafruit_ADS1X15.h>
#include <Adafruit_INA219.h>

// #include <ArduinoJson.h>

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
void loop()



#endif