#include "Uniholic.h"
#include <inttypes.h>

Uniholic::Uniholic(void){
  
}

void Uniholic::begin(void){
  ////////////////////////////////
  //                            //
  //  UNIHOLIC SPECIFICS        //
  //                            //
  ////////////////////////////////

  // These Pins are Hardware-Bound Outputs
  // Pin 10 and 2 should not be set LOW at the same time
  // because they control common-output buffers
  uint8_t p[5] =       {2,    9,    10,   11,  13}; 
  uint8_t p_state[5] = {HIGH, LOW, HIGH, LOW, LOW};
  for(uint8_t i = 0; i < 5; i++){
    digitalWrite(p[i], p_state[i]);
    pinMode(p[i], OUTPUT);        
  }       
        
  //pinMode(8, INPUT_PULLUP);  // WiFi IRQ Signal        
  //pinMode(12, INPUT_PULLUP); // MISO 
}
