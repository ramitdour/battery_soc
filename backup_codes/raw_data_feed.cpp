#include <Arduino.h>

#include <Adafruit_ADS1X15.h>

#include <ArduinoJson.h>

#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(30, D6, NEO_GRB + NEO_KHZ800);

void print_to_serial();

void set_color(uint8_t r, uint8_t g, uint8_t b)
{
  for (int i = 0; i < 30; i++)
  {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.show();
}

void set_ina219_neopixle()
{
  pixels.begin();
  pixels.show(); // Initialize all pixels to 'off'

  uint32_t currentFrequency;

  Serial.println("Hello!");

  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  if (!ina219.begin())
  {
    Serial.println("Failed to find INA219 chip");
    while (1)
    {
      delay(10);
    }
  }
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  // ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  ina219.setCalibration_16V_400mA();

  Serial.println("Measuring voltage and current with INA219 ...");
}

Adafruit_ADS1115 ads;

int16_t adc0, adc1, adc2, adc3;
float volts0, volts1, volts2, volts3;

float volts0_sum = 0;
float volts1_sum = 0;
float volts2_sum = 0;
float volts3_sum = 0;

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.setDebugOutput(true);
  delay(1000);

  set_ina219_neopixle();

  delay(1000);

  //  ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
  ads.begin();
}

void loop()
{
  print_to_serial();
}

uint32_t s_p_counter = 0;

void print_to_serial()
{
  // millis() ; counter ; shunt_volt(uV) ; raw shunt v ;bus_volt(V) ; acd0 raw; adc_v0
  s_p_counter++;
  float s_v = ina219.getShuntVoltage_mV();
  float b_v = ina219.getBusVoltage_V();
 
  int16_t shunt_v_raw = ina219.getShuntVoltage_raw();

  float shunt_v_calb = shunt_v_raw * (0.01) ;

  int16_t adc0_raw = ads.readADC_SingleEnded(0);
  float volts0_adc = ads.computeVolts(adc0_raw);

  Serial.print(millis());
  Serial.print(";\t");

  Serial.print(s_p_counter);
  Serial.print(";\t");

  Serial.print(s_v*1000, 3);
  Serial.print(";\t");

  Serial.print(shunt_v_raw);
  Serial.print(";\t");

  Serial.print(b_v, 3);
  Serial.print(";\t");

  Serial.print(adc0_raw);
  Serial.print(";\t");

  Serial.print((volts0_adc * 23.034246575), 3);
  Serial.println(";");

  // delay(200);
}