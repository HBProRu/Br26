#ifndef _PID_V1_h
#define _PID_V1_h

#define LIBRARY_VERSION	1.0.0

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class PID
{


public:

	//Constants used in some of the functions below
#define AUTOMATIC	1
#define MANUAL	0
#define DIRECT  0
#define REVERSE  1

	//Создает ПИД регулятор
	//	PID(&Input, &Output, &Setpoint, Kp, Ki, Kd, Direction)
	//	Параметры :
	//		  &Input(double) — Входящий сигнал, который мы контролируем
	//		  &Output(double) — Выходящий сигнал, которым мы управляем
	//		  &Setpoint(double) — Заданное значение контролируемого сигнала
	//		  Kp(double >= 0) — пропорциональная составляющая пид - регулятора
	//		  Ki(double >= 0) — интегральная составляющая пид - регулятора
	//		  Kd(double >= 0) — дифференциальная составляющая пид - регулятора
	//		  Direction(DIRECT or REVERSE) направление изменения выходного сигнала
	PID(double*, double*, double*, double, double, double, int);

	//Устанавливает, будет ли ПИД - регулятор включен во время создания.
	//	AUTOMATIC — будет, MANUAL — нет
	//	По умолчанию ПИД - регулятор выключен.
	// * sets PID to either Manual (0) or Auto (non-0)
	void SetMode(int Mode);               

	//Расчет выходного сигнала
	//	Возвращает функция :
	//		True : когда выходной сигнал рассчитан (расчет ведется с периодичностью заданной SetSampleTime)
	//		False : когда ничего не было сделано
	void Compute();

	//Устанавливает границы выходящего сигнала (по умолчанию это 0 - 255)
	//clamps the output to a specific range. 0-255 by default, but
	//it's likely the user will want to change this depending on
	//the application
	void SetOutputLimits(double, double); 

	//Позволяет настраивать ПИД - регулятор во время работы
	//	Параметры:
	//		Kp(double >= 0) — пропорциональная составляющая пид - регулятора
	//		Ki(double >= 0) — интегральная составляющая пид - регулятора
	//		Kd(double >= 0) — дифференциальная составляющая пид - регулятора
	void SetTunings(double, double, double);

	//Направление изменения выходного сигнала, когда начальный входящий сигнал меньше заданного — DIRECT, когда больше REVERSE
	void SetControllerDirection(int);
	
	//Задает частоту расчета выходного сигнала (по умолчанию 100 мили секунд)
	void SetSampleTime(int);

	//Display functions ****************************************************************
	double GetKp();						  // These functions query the pid for interal values.
	double GetKi();						  //  they were created mainly for the pid front-end,
	double GetKd();						  // where it's important to know what is actually 
	int GetMode();						  //  inside the PID.
	int GetDirection();					  //

private:
	void Initialize();

	double dispKp;				// * we'll hold on to the tuning parameters in user-entered 
	double dispKi;				//   format for display purposes
	double dispKd;				//

	double kp;                  // * (P)roportional Tuning Parameter
	double ki;                  // * (I)ntegral Tuning Parameter
	double kd;                  // * (D)erivative Tuning Parameter

	int controllerDirection;

	double *myInput;              // * Pointers to the Input, Output, and Setpoint variables
	double *myOutput;             //   This creates a hard link between the variables and the 
	double *mySetpoint;           //   PID, freeing the user from having to constantly tell us
	//   what these values are.  with pointers we'll just know.

	unsigned long lastTime;
	double ITerm, lastInput;

	unsigned long SampleTime;
	double outMin, outMax;
	bool inAuto;
};
#endif

