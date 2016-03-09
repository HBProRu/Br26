/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Uniholic v1.5, Platform=avr, Package=arduino
*/

#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
#define __AVR_ATmega1284p__
#define __AVR_ATmega1284P__
#define F_CPU 16000000L
#define ARDUINO 10605
#define ARDUINO_AVR_UNIHOLIC
#define ARDUINO_ARCH_AVR
#define __cplusplus 201103L
#define __AVR__
#define __inline__
#define __asm__(x)
#define __extension__
#define __inline__
#define __volatile__
#define GCC_VERSION 40801
#define volatile(va_arg) 
#define _CONST
#define __builtin_va_start
#define __builtin_va_end
#define __attribute__(x)
#define NOINLINE __attribute__((noinline))
#define prog_void
#define PGM_VOID_P int
#ifndef __builtin_constant_p
	#define __builtin_constant_p __attribute__((__const__))
#endif
#ifndef __builtin_strlen
	#define __builtin_strlen  __attribute__((__const__))
#endif
#define NEW_H
typedef void *__builtin_va_list;
typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {;}



#include <arduino.h>
#include <pins_arduino.h> 
#undef F
#define F(string_literal) ((const PROGMEM char *)(string_literal))
#undef PSTR
#define PSTR(string_literal) ((const PROGMEM char *)(string_literal))
#undef cli
#define cli()
#define pgm_read_byte(address_short)
#define pgm_read_word(address_short)
#define pgm_read_word2(address_short)
#define digitalPinToPort(P)
#define digitalPinToBitMask(P) 
#define digitalPinToTimer(P)
#define analogInPinToBit(P)
#define portOutputRegister(P)
#define portInputRegister(P)
#define portModeRegister(P)
#include <..\Br26\Br26.ino>
#include <..\Br26\Adafruit_CC3000.cpp>
#include <..\Br26\Adafruit_CC3000.h>
#include <..\Br26\Adafruit_CC3000_Server.cpp>
#include <..\Br26\Adafruit_CC3000_Server.h>
#include <..\Br26\ArdBir1.h>
#include <..\Br26\DS1307_Wire.h>
#include <..\Br26\DallasTemp.cpp>
#include <..\Br26\DallasTemp.h>
#include <..\Br26\Functions.h>
#include <..\Br26\LCD20x4_RUS.h>
#include <..\Br26\LiquidCrystalRus.cpp>
#include <..\Br26\LiquidCrystalRus.h>
#include <..\Br26\OneWire.cpp>
#include <..\Br26\OneWire.h>
#include <..\Br26\PID_v1.cpp>
#include <..\Br26\PID_v1.h>
#include <..\Br26\Pcb_Uniholic.h>
#include <..\Br26\Presentazione.h>
#include <..\Br26\RTClib.cpp>
#include <..\Br26\RTClib.h>
#include <..\Br26\SPI.cpp>
#include <..\Br26\SPI.h>
#include <..\Br26\Uniholic.cpp>
#include <..\Br26\Uniholic.h>
#include <..\Br26\WiFi_CC3000.h>
#include <..\Br26\Wire.cpp>
#include <..\Br26\Wire.h>
#include <..\Br26\cc_spi.cpp>
#include <..\Br26\cc_spi.h>
#include <..\Br26\cc_util_cc3000_common.cpp>
#include <..\Br26\cc_util_cc3000_common.h>
#include <..\Br26\cc_util_debug.cpp>
#include <..\Br26\cc_util_debug.h>
#include <..\Br26\cc_util_evnt_handler.cpp>
#include <..\Br26\cc_util_evnt_handler.h>
#include <..\Br26\cc_util_hci.cpp>
#include <..\Br26\cc_util_hci.h>
#include <..\Br26\cc_util_netapp.cpp>
#include <..\Br26\cc_util_netapp.h>
#include <..\Br26\cc_util_nvmem.cpp>
#include <..\Br26\cc_util_nvmem.h>
#include <..\Br26\cc_util_security.cpp>
#include <..\Br26\cc_util_security.h>
#include <..\Br26\cc_util_sntp.cpp>
#include <..\Br26\cc_util_sntp.h>
#include <..\Br26\cc_util_socket.cpp>
#include <..\Br26\cc_util_socket.h>
#include <..\Br26\cc_util_wlan.cpp>
#include <..\Br26\cc_util_wlan.h>
#include <C:\Program Files (x86)\Arduino\libraries\Adafruit_CC3000\utility\host_driver_version.h>
#include <..\Br26\twi.c>
#include <..\Br26\twi.h>
#endif
