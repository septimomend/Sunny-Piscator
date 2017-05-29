// Colour Controller.cpp - declaration of class, placed in Colour Controller.h
#include "stdafx.h"
#include "Colour Controller.h"

using namespace std;

ColourController::ColourController() // cstr
{ 
	m_pCrs = 0; 
	m_pClr = 0; 
	m_Back = White; 
	m_Fore = White; 
}

ColourController::ColourController(Cursor* crs) : m_pCrs(crs) // cstr 2
{ 
}

ColourController::ColourController(int x, int y, Cursor* crs, ColourAppearance * clr) // cstr 3
{ 
	m_X = x;
	m_Y = y;
	m_pCrs = crs;
	m_pClr = clr;
}

void ColourController::SetCoordinates(int x, int y)
{
	m_X = x;
	m_Y = y;
}

void ColourController::SetCursor(Cursor* crs) 
{
	m_pCrs = crs;
}

void ColourController::SetColour(colour back, colour fore) 
{
	m_Back = back;
	m_Fore = fore;
}

ColourController::~ColourController() 
{ 
	if (m_pClr) 
		delete[] m_pClr; 
	if (m_pCrs) 
		delete[] m_pCrs; 
}