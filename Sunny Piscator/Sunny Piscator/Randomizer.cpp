// Randomizer.cpp - declaration of class, placed in Randomizer.h
#include "stdafx.h"
#include "Randomizer.h"

Randomizer::Randomizer() : m_Lower(0), m_Upper(RAND_MAX) 
{ 
	time_t seconds; // This type of data used to represent integer – number of seconds, since midnight 00:00
					// Temporary data type time_t able to represent the time and support arithmetic operations.
					// This type of data is used as the return value functions time()
	time(&seconds); // The function returns the current calendar time value in seconds.
					// If the argument is not a null pointer, she passed the time value type time_t - time_t seconds
	srand((unsigned int)seconds); // initializes the random number generator rand
}

void Randomizer::SetBorders (double lower, double upper) 
{ 
	m_Lower = lower; 
	m_Upper = upper; 
}

int Randomizer::Get()
{
	m_Value = rand() % (m_Upper - m_Lower + 1) + m_Lower; // generate random value inside borders
	return m_Value; // return generated random value
}

int Randomizer::GetLast() 
{ 
	return m_Value; // return last value
}