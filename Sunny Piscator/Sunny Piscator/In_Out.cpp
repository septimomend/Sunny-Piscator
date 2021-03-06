// In_Out.cpp - declaration of class, placed in In_Out.h
#include "stdafx.h"
#include "In_Out.h"

using namespace std;

// cstr
//
sInOut::sInOut() : m_Response(false)
{ 
}

// if keyboard's key is pressed
//
void sInOut::YesResponse()
{ 
	m_Response = true;
}

// if keyboard's key is not pressed
//
void sInOut::NoResponse()
{ 
	m_Response = false; 
}

bool sInOut::GetResponse() 
{ 
	return m_Response;
}

// wait for press
//
bool sInOut::Waiting() 
{ 
	return !kbhit(); // returns 0 (means kbhit is false that means key is not pressed)
					 // if kbhit != 0 (ie true) - key pressed
}

// get pressed key
//
void sInOut::Get() 
{ 
	if (m_Response) 
		getche(); // don't need to press enter key after character input
				// getche() function echoes the character to the screen whereas getch() does not do so. 
	else 
		getch(); // also can use getch() instead of getche() function but character input won�t be displayed.
				// The getch() function reads a single character from the keyboard but does not show on the screen. 
				//For this functionality, you can use the getch() function to hold the output window until hitting any key from the keyboard.
}


sInOut& sInOut::operator >> (int& var)
{
	do
	{
		if (m_Response)
			var = getche(); // getche() function echoes the character to the screen whereas getch() does not do so
		else
			var = getch(); // The getch() function reads a single character from the keyboard but does not show on the screen
	} while (var == 0 || var == 224);
	return *this; // returns object
}

sInOut& sInOut::operator >> (char& var)
{
	int k;
	do
	{
		if (m_Response)
			k = getche(); // getche() function echoes the character to the screen whereas getch() does not do so
		else
			k = getch();  // The getch() function reads a single character from the keyboard but does not show on the screen
	} while (k == 0 || k == 224);
	var = (char)k;
	return *this; // returns object
}