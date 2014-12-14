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
#define _VMDEBUG 1
#define ARDUINO 158
#define ARDUINO_MAIN
#define __AVR__
#define __avr__
#define F_CPU 16000000L
#define __cplusplus
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__

#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define __attribute__(x)
#define NOINLINE __attribute__((noinline))
#define prog_void
#define PGM_VOID_P int
            
typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {;}

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
byte Congruita(byte& numRicetta, byte Verso);
void loadRecipe();
void saveRecipe();
void deleteRecipe();
void initializeRecipe();
void RecipeMenu();
void set_hops();
void setup_mode();
//
//

#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\arduino.h"
#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\uniholicv15\pins_arduino.h" 
#include "d:\Gits\Br26\Br26\Br26.ino"
#include "d:\Gits\Br26\Br26\ArdBir1.h"
#include "d:\Gits\Br26\Br26\DS1307_Wire.h"
#include "d:\Gits\Br26\Br26\Functions.h"
#include "d:\Gits\Br26\Br26\LCD20x4_RUS.h"
#include "d:\Gits\Br26\Br26\Pcb_Uniholic.h"
#include "d:\Gits\Br26\Br26\Presentazione.h"
#include "d:\Gits\Br26\Br26\WiFi_CC3000.h"
#endif
