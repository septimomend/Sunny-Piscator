// Shape.h - header file contains declaration of class for describing shapes
#ifndef SHAPE_H
#define SHAPE_H
#include "stdafx.h"
#include "Colour.h"
#include "Cursor.h"

class Shape
{
public:
	Shape(int x, int y); // cstr
	void SetPosition(int x, int y); // sets coordinate position
	void SetController(Cursor* crs_x, ColourAppearance* clr_x); // sets cursor and colour
	void SetColours(colour back_clr); // sets background colour
	void DrawTop(int num); // draws top (hat)
	void DrawSquare(int num); // draws game's square
	void DrawRectangle(int width, int height); // draws rectangle
	void DrawNewcamer(); // draws new player
	void MoveAxisX(int x); // moving at X axis for player

private:
	int m_PosX, m_PosY, m_Temp;
	Cursor* m_pCrs;
	ColourAppearance* m_pClr;
	colour m_Back;
};

#endif // !SHAPE_H
