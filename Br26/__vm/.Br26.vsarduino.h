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
#define ARDUINO 10609
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
extern "C" void __cxa_pure_virtual() {;}



#include <arduino.h>
#include <pins_arduino.h> 
#undef F
#define F(string_literal) ((const PROGMEM char *)(string_literal))
#undef PSTR
#define PSTR(string_literal) ((const PROGMEM char *)(string_literal))")

void Beep(byte NumBeep, int Period);
void Gradi();
void pauseStage();
void dsInizializza();
void Temperature();
void PID_HEAT(boolean autoMode);
void load_pid_settings();
boolean wait_for_confirm(boolean& test, byte Stato, byte Tipo, byte Display);
void quit_mode(boolean& processLoop);
void allOFF();
void heat_on();
void heat_off(boolean mheat);
void heat_control();
void pump_on();
void pump_off(boolean mpump);
void pump_prime();
void pump_control();
void pump_rest(byte stage);
void start_time();
void Timing(byte stage, boolean Test, byte Type);
void hop_add();
void stage_loop();
void add_malt();
void Iodine_Test();
void remove_malt();
void manual_mode();
void WaitStart();
void Temperatura_Raggiunta();
void auto_mode();
void set_PID();
void set_Unit();
void set_Stages();
void set_General();
void set_DateTime();
byte Congruita(byte& numRicetta, byte Verso);
void loadRecipe();
void saveRecipe();
void deleteRecipe();
void initializeRecipe();
void RecipeMenu();
void set_hops();
void setup_mode();
//
String getTimeNowStr();
String getDateTimeNowStr();
String dateElementStr(String str);
//
boolean cc3000_init();
#include "Br26.ino"
#endif
