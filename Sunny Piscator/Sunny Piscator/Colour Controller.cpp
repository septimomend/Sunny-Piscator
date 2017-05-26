// Colour Controller.cpp - declaration of class, placed in Colour Controller.h
#include "stdafx.h"
#include "Colour Controller.h"

using namespace std;

ColourController::ColourController() // cstr
{ 
	m_Crs = 0; 
	m_Clr = 0; 
	m_Back = White; 
	m_Fore = White; 
}

ColourController::ColourController(Cursor* crs) : m_Crs(crs) // cstr 2
{ 
}

ColourController::ColourController(int x, int y, Cursor* crs, ColourAppearance * clr) // cstr 3
{ 
	m_X = x;
	m_Y = y;
	m_Crs = crs;
	m_Clr = clr;
}

void ColourController::SetCoordinates(int x, int y)
{
	m_X = x;
	m_Y = y;
}

void ColourController::SetCursor(Cursor* crs) 
{
	m_Crs = crs;
}

void ColourController::SetColour(colour back, colour fore) 
{
	m_Back = back;
	m_Fore = fore;
}

ColourController::~ColourController() 
{ 
	if (m_Clr) 
		delete[] m_Clr; 
	if (m_Crs) 
		delete[] m_Crs; 
}