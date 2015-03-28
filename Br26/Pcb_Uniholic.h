// sensor and lcd per PCB Uniholic
OneWire ds(19);
LiquidCrystalRus lcd(14, 15, 27, 26, 25, 24);

// push buttons
const char  Button_up = 20;//A6;
const char  Button_dn = 21;//A7;
const char  Button_start = 22;//A4;
const char  Button_enter = 23;//A5;

// outputs
const int Pump = 3;
const int Heat = 4;
const int Heat2 = 5;
const int Buzz = 18;

// leds
const int P_Led = 28;
const int H_Led = 29;