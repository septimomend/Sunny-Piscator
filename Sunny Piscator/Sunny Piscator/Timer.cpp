// Timer.cpp - declaration of class, placed in Timer.h
#include "stdafx.h"
#include "Timer.h"

using namespace std;

Timer::Timer() : m_ProcessElapsed(0), m_bRunning(false) // timer not running
{
}

void Timer::Start()
{
	m_ProcessTime = clock(); // clock() returns the number of time slots, passed from the start of the program.
							 // Via Macro CLOCKS_PER_SEC function gets the number of cycles passed 1 second.
							 // Thus, knowing how many runs cycles per second, knowing the launch of the program can calculate the time of the
							 // entire program or its individual fragments, which makes this function.
	m_bRunning = true; // means timer is running
}

float Timer::Stop()
{
	m_bRunning = false; // timer is stopped
	m_ProcessElapsed = clock() - m_ProcessTime; // how many cycles of time elapsed
	return float(m_ProcessElapsed) / CLOCKS_PER_SEC; // Via Macro CLOCKS_PER_SEC function gets the number of cycles passed 1 secon
													 // ie returns  time in seconds
}

void Timer::Reset()
{
	if (!m_bRunning)
		m_ProcessElapsed = 0; // just resets timer
}

float Timer::CurrentTime()
{
	if (m_bRunning)
		return float(clock() - m_ProcessTime) / CLOCKS_PER_SEC; // returns current timer's value in seconds
	else
		return float(m_ProcessElapsed) / CLOCKS_PER_SEC; // returns elapsed time in seconds
}