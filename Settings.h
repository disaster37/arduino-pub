#ifndef Settings_h
#define Settings_h

// Pin for LCD
static const uint8_t PIN_LCD_RS = 31;
static const uint8_t PIN_LCD_ENABLE = 33;
static const uint8_t PIN_LCD_D0 = 22;
static const uint8_t PIN_LCD_D1 = 23;
static const uint8_t PIN_LCD_D2 = 24;
static const uint8_t PIN_LCD_D3 = 25;
static const uint8_t PIN_LCD_D4 = 26;
static const uint8_t PIN_LCD_D5 = 27;
static const uint8_t PIN_LCD_D6 = 28;
static const uint8_t PIN_LCD_D7 = 29;
static const uint8_t PIN_LCD_CONTRAST = 32;
static const uint8_t PIN_LCD_LED = 30;

// Pin for Button to all start / stop
static const uint8_t PIN_BUTTON_ALL = 35;
static const uint8_t PIN_BUTTON_ALL_LED = 34;

// Pin for Button UVC1 start / stop
static const uint8_t PIN_BUTTON_UVC1 = 37;
static const uint8_t PIN_BUTTON_UVC1_LED = 36;

// Pin for Button UVC2 start / stop
static const uint8_t PIN_BUTTON_UVC2 = 37;
static const uint8_t PIN_BUTTON_UVC2_LED = 36;

// Pin for Button filter bubbler start / stop
static const uint8_t PIN_BUTTON_FILTER_BUBBLER = 43;
static const uint8_t PIN_BUTTON_FILTER_BUBBLER_LED = 42;

// Pin for Button pond bubbler start / stop
static const uint8_t PIN_BUTTON_POND_BUBLER = 45;
static const uint8_t PIN_BUTTON_POND_BUBLER_LED = 44;

// Pin for button pond pump start / stop
static const uint8_t PIN_BUTTON_POND_PUMP = 39;
static const uint8_t PIN_BUTTON_POND_PUMP_LED = 38;

// Pin for button waterfall pump start / stop
static const uint8_t PIN_BUTTON_WATERFALL_PUMP = 39;
static const uint8_t PIN_BUTTON_WATERFALL_PUMP_LED = 38;

// Pin for button LCD selector
static const uint8_t PIN_BUTTON_LCD_DISPLAY_DOWN = 41;
static const uint8_t PIN_BUTTON_LCD_DISPLAY_DOWN_LED = 40;


// Pin for watter security captor
static const uint8_t PIN_WATTER_SECURITY_CAPTOR_TOP = 50;
static const uint8_t PIN_WATTER_SECURITY_CAPTOR_DOWN = 51;


// Pin for UVC1 relay
static const uint8_t PIN_RELAY_UVC1 = 46;

// Pin for UVC2 relay
static const uint8_t PIN_RELAY_UVC2 = 46;

// Pin for filter bubbler relay
static const uint8_t PIN_RELAY_FILTER_BUBBLER = 46;

// Pin for pond bubbler relay
static const uint8_t PIN_RELAY_POND_BUBLER = 46; 

// Pin for pond pump
static const uint8_t PIN_RELAY_POND_PUMP = 47;

// Pin for waterfall pump
static const uint8_t PIN_RELAY_WATERFALL_PUMP = 47;

#endif
