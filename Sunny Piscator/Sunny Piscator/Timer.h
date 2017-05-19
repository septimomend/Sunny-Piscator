// Timer.h - header file for definitiond timer class
#ifndef TIMER_H
#define TIMER_H
#include "stdafx.h"

class Timer
{
public:
	Timer(); // cstr
	void Start(); // starts timer
	float Stop(); // stops timer and returns the time
	void Reset(); // resets timer to zero
	float CurrentTime(); // returns the current time (without stopping timer)
private:
	clock_t m_ProcessTime, m_ProcessElapsed;
	bool m_bRunning;
};

#endif // !TIMER_H

