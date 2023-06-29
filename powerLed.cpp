
#include "PowerLed.h"

powerLed :: powerLed( 
                    LedColor_Type _color,
                    LedState_Type _state,
                    LedDiameter_Type _diameter,
                    LedCurrent_Type _current,
                    LedVoltage_Type _voltage)
                    :Led(_color,_state),
                    diameter(_diameter),
                    current(_current),
                    voltage(_voltage)
{
    // Led_ctor(&this->super,&_color, &_state);
    // this->diathister = _diathister;
    // this->voltage  = _voltage;
    // this->current  = _current;
}
void powerLed :: powerLed_setCurrent ( LedCurrent_Type _current )
{
    this->current = _current;
}
void powerLed :: powerLed_setDiameter( LedDiameter_Type _diathister )
{
    this->diameter = _diathister;
}
void powerLed :: powerLed_setVoltage ( LedVoltage_Type _voltage )
{
    this->voltage = _voltage;
}
Led_Elec_Type powerLed :: PowerLed_computePower()
{
    Led_Elec_Type retPower = (this->current)*(this->current)*(this->voltage);
    return retPower;
}
Led_Elec_Type powerLed :: PowerLed_getCurrent  ()
{
    return this->current;
}
Led_Elec_Type powerLed :: PowerLed_getDiameter ()
{
    return this->diameter;
}
Led_Elec_Type powerLed :: PowerLed_getVoltage  ()
{
    return this->voltage;
}