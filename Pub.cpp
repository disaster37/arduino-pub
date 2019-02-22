#include "Arduino.h"
#include "Pub.h"
#include "Bounce2.h"
#include "PinOutput.h"
#include "LiquidCrystal.h"
#include "timer.h"



/**
 * Constructor
 */
Pub::Pub()
{

  // Button
  _buttonAll = Bounce();
  _buttonUVC1 = Bounce();
  _buttonUVC2 = Bounce();
  _buttonFilterBubbler = Bounce();
  _buttonPondBubbler = Bounce();
  _buttonPondPump = Bounce();
  _buttonPondWaterfall = Bounce();
  _buttonLCDDisplayDown = Bounce();

  // Watter Captor
  _captorWatterSecurityTop = Bounce();
  _captorWatterSecurityDown = Bounce();

  
  // relay
  _relayUVC1 = PinOutput();
  _relayUVC2 = PinOutput();
  _relayFilterBubbler = PinOutput();
  _relayPondBubbler = PinOutput();
  _relayPondPump = PinOutput();
  _relayWaterfallPump = PinOutput();
  
  // Button led
  _buttonUVC1Led = PinOutput();
  _buttonUVC2Led = PinOutput();
  _buttonFilterBubblerLed = PinOutput();
  _buttonPondBubblerLed = PinOutput();
  _buttonPondPumpLed = PinOutput();
  _buttonWaterfallLed = PinOutput();
  _buttonLCDDisplayDownLed = PinOutput();

  // Variable init
  _isAll = false;
  _isUVC1On = false;
  _isUVC2On = false;
  _isFilterBubblerOn = false;
  _isPondBubblerOn = false;
  _isPondPumpOn = false;
  _isWaterfallPumpOn = false;
  _isStart = false;

  // Timers
  _timerLCDRefresh = Timer();
  _timerLCDRefresh.setTimerInMilli(LCD_REFRESH_MILLIS);
  _timerLedLightDuration = Timer();
  _timerLedLightDuration.SetTimerInSecond(60);

}

/**
 * Attach the relay for UVC1
 */
void Pub::attachRelayUVC1(uint8_t pin){
  _relayUVC1.attach(pin);
}

/**
 * Attach the relay for UVC2
 */
void Pub::attachRelayUVC2(uint8_t pin){
  _relayUVC2.attach(pin);
}

/**
 * Attach the relay for filter bubbler
 */
void Pub::attachRelayFilterBubbler(uint8_t pin){
  _relayFilterBubbler.attach(pin);
}

/**
 * Attach the relay for pond bubbler
 */
void Pub::attachRelayPondBubbler(uint8_t pin){
  _relayPondBubbler.attach(pin);
}

/**
 * Attach the relay for pond pump
 */
void Pub::attachRelayPondPump(uint8_t pin){
  _relayPondPump.attach(pin);
}

/**
 * Attach the relay for waterfall pump
 */
void Pub::attachRelayWaterfallPump(uint8_t pin){
  _relayWaterfallPump.attach(pin);
}

/**
 * Attach the all button pin
 */
void Pub::attachButtonAll(uint8_t pin, uint8_t pinLed) {
  _buttonAll.attach(pin, INPUT_PULLUP);
  _buttonAllLed.attach(pinLed);
}

/**
 * Attach the UVC1 button pin
 */
void Pub::attachButtonUVC1(uint8_t pin, uint8_t pinLed) {
  _buttonUVC1.attach(pin, INPUT_PULLUP);
  _buttonUVC1Led.attach(pinLed);
}

/**
 * Attach the UVC2 button pin
 */
void Pub::attachButtonUVC2(uint8_t pin, uint8_t pinLed) {
  _buttonUVC2.attach(pin, INPUT_PULLUP);
  _buttonUVC2Led.attach(pinLed);
}

/**
 * Attach the filter bubbler button pin
 */
void Pub::attachButtonFilterBubbler(uint8_t pin, uint8_t pinLed) {
  _buttonFilterBubbler.attach(pin, INPUT_PULLUP);
  _buttonFilterBubblerLed.attach(pinLed);
}

/**
 * Attach the pond bubbler button pin
 */
void Pub::attachButtonPondBubbler(uint8_t pin, uint8_t pinLed) {
  _buttonPondBubbler.attach(pin, INPUT_PULLUP);
  _buttonPondBubblerLed.attach(pinLed);
}

/**
 * Attach the pond pump button pin
 */
void Pub::attachButtonPondPump(uint8_t pin, uint8_t pinLed) {
  _buttonPondPump.attach(pin, INPUT_PULLUP);
  _buttonPondPumpLed.attach(pinLed);
}

/**
 * Attach the waterfall pump button pin
 */
void Pub::attachButtonWaterfallPump(uint8_t pin, uint8_t pinLed) {
  _buttonWaterfallPump.attach(pin, INPUT_PULLUP);
  _buttonWaterfallPumpLed.attach(pinLed);
}


/**
 * Attach the pin to down message on LCD display
 */
void Pub::attachButtonLCDDisplayDown(uint8_t pin, uint8_t pinLed) {
  _buttonLCDDisplayDown.attach(pin, INPUT_PULLUP);
  _buttonLCDDisplayDownLed.attach(pinLed);
}


/**
 * Attach the 2 pin of the security watter captor
 */
void Pub::attachCaptorWaterSecurity(uint8_t pinCaptorTop, uint8_t pinCaptorDown) {
  _captorWaterSecurityTop.attach(pinCaptorTop, INPUT_PULLUP);
  _captorWaterSecurityDown.attach(pinCaptorDown, INPUT_PULLUP);
}

/**
 * Attach the LCD pin to display on LCD
 */
void Pub::attachLCD(uint8_t pinRS, uint8_t pinEnable, uint8_t pinD0, uint8_t pinD1, uint8_t pinD2, uint8_t pinD3, uint8_t pinD4, uint8_t pinD5, uint8_t pinD6, uint8_t pinD7, uint8_t pinContrast, uint8_t pinLed) {
  _lcd = LiquidCrystal(pinRS, pinEnable, pinD0, pinD1, pinD2, pinD3, pinD4, pinD5, pinD6, pinD7);
  _lcdLed.attach(pinLed);

  analogWrite(pinContrast, 15);
  _lcd.begin(16, 2); // règle la taille du LCD : 16 colonnes et 2 lignes
  _lcd.display();
}

/**
 * Start UVC1
 */
void Pub::_startUVC1() {
  _isUVC1On = true;
  _relayUVC1.toUp();
}

/**
 * Start UVC2
 */
void Pub::_startUVC2() {
  _isUVC2On = true;
  _relayUVC2.toUp();
}

/**
 * Start filter bubbler
 */
void Pub::_startFilterBubbler() {
  _isFilterBubblerOn = true;
  _relayFilterBubbler.toUp();
}

/**
 * Start pond bubbler
 */
void Pub::_startPondBubbler() {
  _isPondBubblerOn = true;
  _relayPondBubbler.toUp();
}

/**
 * Start pond pump
 */
void Pub::_startPondPump() {
  _isPondPump = true;
  _relayPondPump.toUp();
}

/**
 * Start waterfall pump
 */
void Pub::_startWaterfallPump() {
  _isWaterfallPumpOn = true;
  _relayWaterfallPump.toUp();
}

/**
 * Start all
 */
void Pub::_startAll() {
  _startUVC1();
  _startUVC2();
  _startFilterBubbler();
  _startPondBubbler();
  _startPondPump();
  _startWaterfallPump();
}

/**
 * Stop the UVC1
 */
void Pub::_stopUVC1() {
  _isUVC1On = false;
  _relayUVC1.toDown();
}

/**
 * Stop the UVC2
 */
void Pub::_stopUVC2() {
  _isUVC2On = false;
  _relayUVC2.toDown();
}

/**
 * Stop the filter bubbler
 */
void Pub::_stopFilterBubbler() {
  _isFilterBubblerOn = false;
  _relayFilterBubbler.toDown();
}

/**
 * Stop the pond bubbler
 */
void Pub::_stopPondBubbler() {
  _isPondBubblerOn = false;
  _relayPondBubbler.toDown();
}

/**
 * Stop the pond pump
 */
void Pub::_stopPondPump() {
  _isPonPumpOn = false;
  _relayPondPump.toDown();
}

/**
 * Stop the waterfall pump
 */
void Pub::_stopWaterfallPump() {
  _isWaterfallPumpOn = false;
  _relayWaterfallPump.toDown();
}

/**
 * Stop all
 */
void Pub::_stopAll() {
  _stopUVC1();
  _stopUVC2();
  _stopFilterBubbler();
  _stopPondBubbler();
  _stopPondPump();
  _stopWaterfallPump();
}

/**
 * Stop security
 */
void Pub::_stopSecurity() {
  _stopUVC1();
  _stopUVC2();
  _stopPondPump();
  _stopWaterfallPump();
}



void Fat::displayMessage() {

  // Manage position
  if(_buttonLCDDisplayDown.fell()) {
    if(_messagePosition < (SIZE_MESSAGE -1)) {
      _messagePosition++;
    }
    else {
      _messagePosition = 0;
    }
  }
  
  String stateUVC1 = "";
  String stateUVC2 = "";
  String stateFilterBubbler = "";
  String statePondBubbler = "";
  String statePondPump = "";
  String stateWaterfallPump = "";
  
  if(_isUVC1On) {
    stateUVC1 = "on ";
  }
  else {
    stateUVC1 = "off";
  }
  
  if (_isUVC2On) {
    stateUVC2 = "on ";
  }
  else {
    stateUVC2 = "off";
  }
  
  if (_isFilterBubblerOn) {
    stateFilterBubbler = "on ";
  }
  else {
    stateFilterBubbler = "off";
  }
  
  if (_isPondBubblerOn) {
    statePondBubbler = "on ";
  }
  else {
    statePondBubbler = "off";
  }
  
  if (_isPondPumpOn) {
    statePondPump = "on ";
  }
  else {
    statePondPump = "off";
  }
  
  if (_isWaterfallPump) {
    stateWaterfallPump = "on ";
  }
  else {
    stateWaterfallPump = "off";
  }
  
  // Compose all messages
  _message[0] = String("UV1:") + stateUVC1 + String("UV2:") + stateUVC2;
  _message[1] = String("P1:") + statePondPump + String(" P2:") + stateWaterfallPump;
  _message[2] = String("B1:") + stateFilterBubbler + String(" B2:") + statePondBubbler;

  _message[3] = String("Captor2 T: ") + (!_captorWaterSecurityTop.read());
  _message[4] = String("Captor2 D: ") + (_captorWaterSecurityDown.read());
  
  // Display message
  if(_timerLCDRefresh.isJustFinished()) {
    _lcd.clear();
    char temp[16];
    _lcd.setCursor(0,0);
    _message[_messagePosition].toCharArray(temp, 16);
    _lcd.write(temp);
  
    _lcd.setCursor(0, 1);
    if(_messagePosition < (SIZE_MESSAGE -1)) {
      _message[_messagePosition + 1].toCharArray(temp, 16);
      _lcd.write(temp);
    }
    else {
       String("               ").toCharArray(temp, 16);
       _lcd.write(temp);
    }
    
  } else if (_timerLCDRefresh.isRun() == false) {
    // Run the timer
    _timerLCDRefresh.start();
  }
}

/**
 * The main function that check if fonction is needed depend to button or captor
 */
void Fat::run() {

  _updateInputState();
  _manageLed();
  displayMessage();
  
  // Check if system just start
  if(_isStart == false) {
    _isStart = true;  
    _startAll();
  }
  
  // Manage all
  if(_buttonAll.fell()) {
    if(_isAllOn == true) {
      _stopAll();
    }
    else {
      _startAll();
    }
  }
  
  // Manage filter bubbler
  if(_buttonFilterBubbler.fell()) {
    if(_isFilterBubblerOn == true) {
      _stopFilterBubbler();
    }
    else {
      _startFilterBubbler();
    }
  }
  
  // Manage pond bubbler
  if(_buttonPondBubbler.fell()) {
    if(_isPondBubblerOn == true) {
      _stopPondBubbler();
    }
    else {
      _startPondBubbler();
    }
  }

  // Authorize to start / stop UVCs and pump only if secturity captor is OK
  if((_captorWaterSecurityDown.read() == LOW) || (_captorWaterSecurityTop.read() == HIGH)) {
    _stopSecurity();
  }
  else {
    // Manage UVC1 button
    if(_buttonUVC1.fell()) {
      if(_isUVC1On == true) {
        _stopUVC1();
      }
      else {
        _startUVC1();
      }
    }
    
    // Manage UVC2 button
    if(_buttonUVC2.fell()) {
      if(_isUVC2On == true) {
        _stopUVC2();
      }
      else {
        _startUVC2();
      }
    }
    
    // Manage pond pump button
    if(_buttonPondPump.fell()) {
      if(_isPondPumpOn == true) {
        _stopPondPump();
      }
      else {
        _startPondPump();
      }
    }
    
    // Manage waterfall pump button
    if(_buttonWaterfallPump.fell()) {
      if(_isWaterfallPumpOn == true) {
        _stopWaterfallPump();
      }
      else {
        _startWaterfallPump();
      }
    }
  }
}



/**
 * Permit to update the input state
 */
void Fat::_updateInputState() {

  _buttonAll.update();
  _buttonUVC1.update();
  _buttonUVC2.update();
  _buttonFilterBubbler.update();
  _buttonPondBubbler.update();
  _buttonPondPump.update();
  _buttonWaterfallPump.update();
  _buttonLCDDisplayDown.update();
  
  _captorWaterSecurityTop.update();
  _captorWaterSecurityDown.update();
  
  _timerLCDRefresh.update();
  _timerLedLightDuration.update();
}

/**
 * Permit to manage all led (button and lcd)
 */
void Fat::_manageLed() {

  // Comptute the led state
  if (_buttonAll.fell() || _buttonUVC1.fell() || _buttonUVC2.fell() || _buttonFilterBubbler.fell() || _buttonPondBubbler.fell() || _buttonPondPump.fell() || _buttonWaterfallPump.fell() || _buttonLCDDisplayDown.fell()) {
    _timerLedLightDuration.start();
    _isLedLight = true;
  }

  if (_timerLedLightDuration.isJustFinished()) {
    _isLedLight = false;
  }

  if(_isLedLight) {
    _buttonAllLed.toUp();
    _buttonUVC1Led.toUp();
    _buttonUVC2Led.toUp();
    _buttonFilterBubblerLed.toUp();
    _buttonPondBubblerLed.toUp();
    _buttonPondPumpLed.toUp();
    _buttonWaterfallPumpLed.toUp();
    _buttonLCDDisplayDownLed.toUp();
    _lcdLed.toUp();
  }
  else{
    _buttonAllLed.toDown();
    _buttonUVC1Led.toDown();
    _buttonUVC2Led.toDown();
    _buttonFilterBubblerLed.toDown();
    _buttonPondBubblerLed.toDown();
    _buttonPondPumpLed.toDown();
    _buttonWaterfallPumpLed.toDown();
    _buttonLCDDisplayDownLed.toDown();
    _lcdLed.toDown();
  }
}




void Fat::debug(){

  _updateInputState();

  // Display debug message
  _lcd.setCursor(0,0);
  char debug[16] = "DEBUG";
  _lcd.write(debug);

  // put all leds on
  _isLedLight = true;
  _manageLed();

  // Display button state
  Serial.println(String("Btn All: ") + (!_buttonAll.read()));
  Serial.println(String("Btn UVC1: ") + (!_buttonUVC1.read()));
  Serial.println(String("Btn UVC2: ") + (!_buttonUVC2.read()));
  Serial.println(String("Btn FilterBubbler: ") + (!_buttonFilterBubbler.read()));
  Serial.println(String("Btn PondBubbler: ") + (!_buttonPondBubbler.read()));
  Serial.println(String("Btn PondPump: ") + (!_buttonPondPump.read()));
  Serial.println(String("Btn WaterfallPump: ") + (!_buttonWaterfallPump.read()));
  Serial.println(String("Btn menu: ") + (!_buttonLCDDisplayDown.read()));

  // Display captor state
  Serial.println(String("Cpt top: ") + (!_captorWaterSecurityTop.read()));
  Serial.println(String("Cpt down: ") + (_captorWaterSecurityDown.read()));

  // Display relay state
  Serial.println(String("Relay UVC1: ") + _relayUVC1.state());
  Serial.println(String("Relay UVC2: ") + _relayUVC2.state());
  Serial.println(String("Relay FilterBubbler: ") + _relayFilterBubbler.state());
  Serial.println(String("Relay PondBubbler: ") + _relayPondBubbler.state());
  Serial.println(String("Relay PondPump: ") + _relayPondPump.state());
  Serial.println(String("Relay WaterfallPump: ") + _relayWaterfallPump.state());
   
  
  delay(2000);
}


