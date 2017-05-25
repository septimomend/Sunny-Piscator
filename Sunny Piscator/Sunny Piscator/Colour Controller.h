// Colour Controller.h - header file contains declaration of class for controlling colour
#ifndef COLOUR_CONTROLLER_H
#define COLOUR_CONTROLLER_H
#include "stdafx.h"
#include "Colour.h"
#include "Cursor.h"

class ColourController
{
public:
	ColourController(); // cstr
	ColourController(Cursor* crs);
	ColourController(int x, int y, Cursor* crs, ColourAppearance* clr);
	void SetCoordinates(int x, int y); // sets coordinates
	void SetCursor(Cursor* crs); // sets cursor position
	void SetColour(colour back, colour fore); // sets colours
	~ColourController(); // dstr 

protected:
	colour m_Back, m_Fore;
	int m_X, m_Y;
	Cursor* m_Crs; // cursor
	ColourAppearance* m_Clr; // colour
};

#endif // !COLOUR_CONTROLLER_H
