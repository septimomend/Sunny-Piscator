// Piscator.h - header file contains declaration of class that describes main game's object - piscator
#ifndef PISCATOR_H
#define PISCATOR_H
#include "stdafx.h"
#include "Colour.h"
#include "Cursor.h"
#include "Limn.h"

class Piscator : public Limn
{
public:
	Piscator();
	void SetController(Cursor* crs, ColourAppearance* clr);
	void Move(char direction); // moving of piscator using direction arrows or A/D buttons
	int GetPstrX(); // returns the X postion of the piscator (cursor) 

protected:
	int m_pstrX, m_pstrY;
};
#endif // !PISCATOR_H
