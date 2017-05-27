// Shape.cpp - definition of class, placed in Shape.h
#include "stdafx.h"
#include "Shape.h"

/*
* cstr
*/
Shape::Shape(int x, int y) : m_PosX(x), m_PosY(y)
{  
	m_pCrs = 0; 
	m_pClr = 0; 
}

/*
* set position
*/
void Shape::SetPosition(int x, int y) 
{ 
	m_PosX = x;
	m_PosY = y;
}

/*
* set cursor and colour controllers
*/
void Shape::SetController(Cursor* crs_x, ColourAppearance* clr_x)
{
	m_pCrs = crs_x;
	m_pClr = clr_x;
}

/*
* set background colour
*/
void Shape::SetColours(colour back_clr) 
{ 
	m_Back = back_clr;
}