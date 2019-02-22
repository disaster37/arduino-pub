#ifndef Pub_h
#define Pub_h

#include "Arduino.h"
#include "Bounce2.h"
#include "PinOutput.h"
#include "LiquidCrystal.h"
#include "timer.h"

#define SIZE_MESSAGE 11
#define LCD_REFRESH_MILLIS 200

class Pub
{
  public:
    Pub();
    void attachRelayUVC1(uint8_t pin);
    void attachRelayUVC2(uint8_t pin);
    void attachRelayFilterBubbler(uint8_t pin);
    void attachRelayPondBubbler(uint8_t pin);
    void attachRelayPondPump(uint8_t pin);
    void attachRelayWaterfallPump(uint8_t pin);
    
    void attachButtonAll(uint8_t pin, uint8_t pinLed);
    void attachButtonUVC1(uint8_t pin, uint8_t pinLed);
    void attachButtonUVC2(uint8_t pin, uint8_t pinLed);
    void attachButtonFilterBubbler(uint8_t pin, uint8_t pinLed);
    void attachButtonPondBubbler(uint8_t pin, uint8_t pinLed);
    void attachButtonPondPump(uint8_t pin, uint8_t pinLed);
    void attachButtonWaterfallPump(uint8_t pin, uint8_t pinLed);
    void attachCaptorWaterSecurity(uint8_t pinCaptorTop, uint8_t pinCaptorDown);
    void attachLCD(uint8_t pinRS, uint8_t pinEnable, uint8_t pinD0, uint8_t pinD1, uint8_t pinD2, uint8_t pinD3, uint8_t pinD4, uint8_t pinD5, uint8_t pinD6, uint8_t pinD7, uint8_t pinContrast, uint8_t pinLed);
    void run();
    void displayMessage();
    void debug();
  private:
    PinOutput _relayUVC1;
    PinOutput _relayUVC2;
    PinOutput _relayFilterBubbler;
    PinOutput _relayPondBubbler;
    PinOutput _relayPondPump;
    PinOutput _relayWaterfallPump;
    Bounce _buttonAll;
    PinOutput _buttonAllLed;
    Bounce _buttonUVC1;
    PinOutput _buttonUVC1Led;
    Bounce _buttonUVC2;
    PinOutput _buttonUVC2Led;
    Bounce _buttonFilterBubbler;
    PinOutput _buttonFilterBubblerLed;
    Bounce _buttonPondBubbler;
    PinOutput _buttonPondBubblerLed;
    Bounce _buttonPondPump;
    PinOutput _buttonPondPumpLed;
    Bounce _buttonWaterfallPump;
    PinOutput _buttonWaterfallPumpLed;
    Bounce _buttonLCDDisplayDown;
    PinOutput _buttonLCDDisplayDownLed;
    Bounce _captorWaterSecurityTop;
    Bounce _captorWaterSecurityDown;
    LiquidCrystal _lcd = LiquidCrystal(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PinOutput _lcdLed;
    String _message[SIZE_MESSAGE];
    int _messagePosition;
    bool _isLedLight;
    Timer _timerLCDRefresh;
    Timer _timerLedLightDuration;
    void _startUVC1();
    void _startUVC2();
    void _startFilterBubbler();
    void _startPondBubbler();
    void _startPondPump();
    void _startWaterfallPump();
    void _startAll();
    void _stopUVC1();
    void _stopUVC2();
    void _stopFilterBubbler();
    void _stopPondBubbler();
    void _stopPondPump();
    void _stopWaterfallPump();
    void _stopAll();
    void _stopSecurity();
    bool _isStart;
    bool _isAllOn;
    bool _isUVC1On;
    bool _isUVC2On;
    bool _isFilterBubblerOn;
    bool _isPondBubblerOn;
    bool _isPondPumpOn;
    bool _isWaterfallPumpOn;
};

#endif
