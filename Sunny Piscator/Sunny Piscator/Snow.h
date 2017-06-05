// Snow.h - header file contains declaration of class that represents snows
#ifndef SNOW_H
#define SNOW_H
#include "stdafx.h"
#include "Colour.h"
#include "Cursor.h"
#include "Limn.h"
#include "Randomizer.h"

class Snow : public Limn
{
public:
	Snow(); // cstr
	void SetController(Cursor* crs, ColourAppearance* clr); // sets cursor and colour
	void SetColours(colour back_clr, colour fore_clr); // sets background colour
	void AddSnowflake(); // add item (snowflake) to array
	void ShowSnow(); // displays snow
	int LeastSnowflake();// check a least snowflake 
	void FillArray(); // fills the array 0 
	void ArrayShift(); // shifts array index down one so that the snowflake look like they are falling
	void ArrayLevel(); // last line of snowflakes

protected:
	char m_SnowArr[38][29]; // [x][y]
};

#endif // !SNOW_H
