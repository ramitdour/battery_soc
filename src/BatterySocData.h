#ifndef BatterySocData_h
#define BatterySocData_h


#define DEBUG_CODE 1 // TODO:comment in productions

#define ADS1115_SENSOR 1 // TODO: uncomment if ADS1115 is used
#define INA219_SENSOR 1 // TODO: uncomment if INA219 is used

#define LCD_16X2_I2C 1 // TODO: uncomment if 16x2 i2c LCD is used
#define LED_7SEG_TM1637_I2C 1 // TODO: uncomment if 4 digit 7 segment dispay is used


#ifdef DEBUG_CODE

//Debug parameters
#define SERIAL_BAUD_RATE 115200

#else

// Production parameters

#endif

#define SHUNT_MAX_VOLTAGE 0.075F            // 75mV voltage drop across shunt on Rated current Flow
#define SHUNT_MAX_CURRENT 50.0F             // 50 A Rated Current of Shunt
#define SHUNT_RESISTANCE  0.0015F           // 1.5mOhm R_shunt = V_max_shunt / I_max_shunt === SHUNT_MAX_VOLTAGE /SHUNT_MAX_CURRENT

#define BATTERY_VOLTAGE 64.0F               //  Rated voltage of battery NORMAL
#define BATTERY_AH  100.00F                 //  Rated Capacity of battery
#define BATTERY_FULL_CHARGE_CYCLE 500       // Battery Full charge Cycle counter limit

#define BATTERY_VOLTAGE_MAX 65.0F           //  Rated voltage of battery on FULL CHARGE
#define BATTERY_VOLTAGE_MIN 62.0F           //  Rated voltage of battery on FULL DISCHARGE

// All currents are in Ampere
#define BATTERY_CURRENT_AVG 20.0F           //  Average current drawn from battry under normal condtions
#define BATTERY_CURRENT_LEAKAGE 0.0001F     //  0.1mA Average current drawn from battry under normal condtions , when power off
#define BATTERY_CURRENT_IDLE 0.001F         //  1mA Average current drawn from battry under normal condtions , when power on but no motor run
#define BATTERY_CURRENT_PEAK 60.0F          //  Average current drawn from battry under normal condtions

//While Charging Parameters
#define BATTERY_CURRENT_CHARGING_MIN 02.0F  //  
#define BATTERY_CURRENT_CHARGING_MAX 10.0F  //
#define BATTERY_CURRENT_CHARGING_AVG 07.0F  //

#define BATTERY_VOLTAGE_FULL_CHARGE 65.0F   //  Voltage across battery when fully CHARGED (Charger still connected)
#define BATTERY_VOLTAGE_MIN_CHARGE  65.0F   //  Voltage across battery when fully DRAINED (Charger still connected)

#define PIN_ANALOG_BATTERY_VOLTAGE A0                   // Will Measure Voltage through Voltage divider circuit across R2
#define R1_VOLTAGE_DIVIDER_BATTERY_VOLTAGE  3200000     //  2.2M + 1M = 3.2M Ohm (Use 2 resistance if one short other will save the circuit)
#define R2_VOLTAGE_DIVIDER_BATTERY_VOLTAGE  157000      //  147k + 10k = 157k Ohm

// FOR FUTURE SCOPE
#define BUTTON_PIN_MODE
#define BUTTON_PIN_SET 
#define BUTTON_PIN_UP
#define BUTTON_PIN_DOWN
#define BUTTON_PIN_ENTER

#define LED_PIN_PWM_RED
#define LED_PIN_PWM_GREEN
#define LED_PIN_PWM_YELLOW

#define BUTTON_PIN_SIDE_STAND
#define BUZZER_PIN_PWM_OUT


#endif