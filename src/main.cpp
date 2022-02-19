#include <Arduino.h>

#include <BatterySoc.h>

Adafruit_INA219 ina219;
Adafruit_ADS1115 ads1115;

void setup()
{

#ifdef DEBUG_CODE

  // Setup serial
  Serial.begin(SERIAL_BAUD_RATE);
  delay(1000);
  Serial.setDebugOutput(true);
  delay(1000);

#endif

#ifdef LCD_16X2_I2C

  setup_lcd_i2c();

#endif

#ifdef LED_7SEG_TM1637_I2C

  setup_7seg_i2c();

#endif

  setup_push_buttons();
  setup_analog_read();

#ifdef ADS1115_SENSOR

  //
  setup_ads1115();

#endif

#ifdef INA219_SENSOR

  setup_ina219();

#endif
}

void loop()
{
}
