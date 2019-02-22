

#include "LiquidCrystal.h" //ajout de la librairie
#include "Bounce2.h"
#include "Settings.h"
#include "PinOutput.h"
#include "Pub.h"



// Create Pub object
Pub pub = Pub();

void setup()
{
  // Init serial consol for debugging
  Serial.begin(9600);

  // Set the relay pin
  pub.attachRelayUVC1(PIN_RELAY_UVC1);
  pub.attachRelayUVC2(PIN_RELAY_UVC2);
  pub.attachRelayFilterBubbler(PIN_RELAY_FILTER_BUBBLER);
  pub.attachRelayPondBubbler(PIN_RELAY_POND_BUBLER);
  pub.attachRelayPondPump(PIN_RELAY_POND_PUMP);
  pub.attachRelayWaterfallPump(PIN_RELAY_WATERFALL_PUMP);

  // Set the button pin
  pub.attachButtonAll(PIN_BUTTON_ALL, PIN_BUTTON_ALL_LED);
  pub.attachButtonUVC1(PIN_BUTTON_UVC1, PIN_BUTTON_UVC1_LED);
  pub.attachButtonUVC2(PIN_BUTTON_UVC2, PIN_BUTTON_UVC2_LED);
  pub.attachButtonFilterBubbler(PIN_BUTTON_FILTER_BUBBLER, PIN_BUTTON_FILTER_BUBBLER_LED);
  pub.attachButtonPondBubbler(PIN_BUTTON_POND_BUBBLER, PIN_BUTTON_POND_BUBBLER_LED);
  pub.attachButtonPondPump(PIN_BUTTON_POND_PUMP, PIN_BUTTON_POND_PUMP_LED);
  pub.attachButtonWaterfallPump(PIN_BUTTON_WATERFALL_PUMP, PIN_BUTTON_WATERFALL_PUMP_LED);
  pub.attachButtonLCDDisplayDown(PIN_BUTTON_LCD_DISPLAY_DOWN, PIN_BUTTON_LCD_DISPLAY_DOWN_LED);

  // Set the watter captor pin
  fat.attachCaptorWaterSecurity(PIN_WATER_SECURITY_CAPTOR_TOP, PIN_WATER_SECURITY_CAPTOR_DOWN);

  // Set the LCD pin
  fat.attachLCD(PIN_LCD_RS, PIN_LCD_ENABLE, PIN_LCD_D0, PIN_LCD_D1, PIN_LCD_D2, PIN_LCD_D3, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7, PIN_LCD_CONTRAST, PIN_LCD_LED);

}
 
void loop()
{

  // Run the PUB
  pub.run();
  //pub.debug();
    
}
