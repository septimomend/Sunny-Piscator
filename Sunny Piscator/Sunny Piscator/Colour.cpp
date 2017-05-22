// Colour.cpp - declaration of class, placed in Colour.h
#include "stdafx.h"
#include "Colour.h"



ColourAppearance::ColourAppearance() : m_Foreground(15), m_Background(0) 
{ 
	m_hOut = GetStdHandle(STD_OUTPUT_HANDLE); // gets a handle for the output device
}

void ColourAppearance::SetForeground(colour c)
{
	if (c < 8) // if value is in enum colour range
		m_Foreground = c + (m_Foreground >= 8) * 8; // if >= 8 get 1 else 0
	SetConsole();
}
	
void ColourAppearance::SetBackground(colour c)
{
	if (c < 8) // if value is in enum colour range
		m_Background = c + (m_Background >= 8) * 8; // if >= 8 get 1 else 0
	SetConsole();
}
	
void ColourAppearance::SetForeBright(bool b)
{
	if (b && m_Foreground < 8)
		m_Foreground += 8; // sets foreground brightness
	else if (!b && m_Foreground >= 8)
		m_Foreground -= 8; // sets foreground brightness
	SetConsole();
}

void ColourAppearance::SetBackBright(bool b)
{
	if (b && m_Background < 8)
		m_Background += 8; // sets background brightness
	else if (!b && m_Background >= 8)
		m_Background -= 8; // sets background brightness
	SetConsole();
}
	
void ColourAppearance::Invert()
{
	m_Foreground = m_Foreground ^ m_Background; // XOR
	m_Background = m_Background ^ m_Foreground; // XOR
	m_Foreground = m_Foreground ^ m_Background; // XOR
	SetConsole();
}

ColourAppearance::~ColourAppearance() 
{ 
	// sets default
	SetForeground(White); 
	SetForeBright(true); 
	SetBackground(Black); 
	SetBackBright(false); 
}

void ColourAppearance::SetConsole() 
{ 
	/**********************************************************************************************************
	* If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. *
	* To get extended error information, call GetLastError.                                                   *
	***********************************************************************************************************/
	SetConsoleTextAttribute(m_hOut, m_Foreground + m_Background * 16); // Sets the attributes of characters written to the console screen buffer by the
																 // WriteFile or WriteConsole function, or echoed by the ReadFile or
																 // ReadConsole function. This function affects text written after the function call.
																 // Gets handle of output device m_hOut and sets the attributes
																 // m_Foreground + m_Background * 16 to characters written to the console screen buffer
																 /**********************************************************************************
																 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms686047(v=vs.85).aspx *
																 ***********************************************************************************/
}