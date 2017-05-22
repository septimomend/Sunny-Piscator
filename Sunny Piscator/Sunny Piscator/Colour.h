// Colour.h - header file contains definition of class representing colour of interface
#ifndef COLOUR_H
#define COLOUR_H
#include "stdafx.h"

enum colour 
{ 
	Black, 
	Blue, 
	Green, 
	Aqua, 
	Red, 
	Purple, 
	Yellow, 
	White 
};

class ColourAppearance
{
public:
	ColourAppearance(); // cstr
	void SetForeground(colour c); // sets foreground
	void SetBackground(colour c); // sets background
	void SetForeBright(bool b); // foreground brightness
	void SetBackBright(bool b); // background brightness
	void Invert();
	~ColourAppearance(); // dstr

private:
	HANDLE m_hOut; // handle is what function working with. Ie this is descriptor of object 
				   /*************************************
				   * http://cppstudio.com/en/post/9489/ *
				   **************************************/
	int m_Foreground, m_Background;
	void SetConsole();
};

#endif // COLOUR_H