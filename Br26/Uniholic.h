
#ifndef _UNIHOLIC_LIB_H
#define _UNIHOLIC_LIB_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class Uniholic {
  private:
  public:
	Uniholic();
	void begin(void);
};

#endif //_UNIHOLIC_LIB_H

