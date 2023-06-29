#ifndef POWERLED_H
#define POWERLED_H
#include "Led.h"

typedef uint8_t Led_Elec_Type;
typedef uint8_t Led_Dim_Type;

typedef enum 
{
    CURR_LOW        = 10,   /*10mA*/
    CURR_NORMAL     = 20,   /*20mA*/
    CURR_HIGH       = 35,   /*35mA*/
    CURR_VERY_HIGH  = 60    /*60mA*/
}LedCurrent_Type;

typedef enum
{
    DIAM_2MM = 2,   /*2mm*/
    DIAM_5MM = 5,   /*5mm*/
    DIAM_7MM = 7,   /*7mm*/
}LedDiameter_Type;

typedef enum 
{
    VOL_LOW     = 3,    /*3 Volts*/
    VOL_NORMAL  = 5,    /*5 Volts*/
    VOL_HIGH    = 9     /*9 Volts*/
}LedVoltage_Type;

class powerLed: public Led
{
    private:
    LedDiameter_Type diameter;
    LedCurrent_Type current;
    LedVoltage_Type voltage;
    public:
    powerLed(
                    LedColor_Type _color,
                    LedState_Type _state,
                    LedDiameter_Type _diameter,
                    LedCurrent_Type _current,
                    LedVoltage_Type _voltage);
    void powerLed_setCurrent (LedCurrent_Type _current );
    void powerLed_setDiameter(LedDiameter_Type _diameter );
    void powerLed_setVoltage (LedVoltage_Type _voltage );
    Led_Elec_Type PowerLed_computePower();
    Led_Elec_Type PowerLed_getCurrent  ();
    Led_Elec_Type PowerLed_getDiameter ();
    Led_Elec_Type PowerLed_getVoltage  ();
};


#endif