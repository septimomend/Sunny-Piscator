// Piscator.cpp - definition of class, placed in Piscator.h
#include "stdafx.h"
#include "Piscator.h"

using namespace std;

Piscator::Piscator() : Limn() // setting default position
{
	m_pstrX = 19;
	m_pstrY = 29;
}

void Piscator::SetController(Cursor* crs, ColourAppearance* clr)  // moving of piscator using direction arrows or A/D buttons
{
	m_pCrs = crs;
	m_pClr = clr;
	m_pClr->SetBackground(Aqua);
	m_pCrs->SetPosition(m_pstrX, m_pstrY, 4); 
	cout << (char)1;
}

void Piscator::Move(char direction)  // returns the X postion of the piscator (cursor) 
{
	if (direction == 77 || direction == 'd')
	{
		if (m_pstrX <= 37)
		{
			m_pCrs->SetPosition(m_pstrX, m_pstrY, 4);
			cout << "  "; // erase last postion
			m_pstrX += 1; // when moving right
			m_pCrs->SetPosition(m_pstrX, m_pstrY, 4);// moving the cursor
			m_pClr->SetBackground(Aqua);
			m_pClr->SetForeground(Yellow);
			cout << (char)2; // piscator
			m_pCrs->SetPosition(m_pstrX, m_pstrY);
		}
	}
	if (direction == 75 || direction == 'a')
	{
		if (m_pstrX >= 3)
		{
			m_pCrs->SetPosition(m_pstrX, m_pstrY, 4);
			cout << "  ";// erase last postion
			m_pstrX -= 1; // when moving left
			m_pCrs->SetPosition(m_pstrX, m_pstrY, 4);// moving the cursor
			m_pClr->SetBackground(Aqua);
			m_pClr->SetForeground(Yellow);
			cout << (char)2; // piscator
			m_pCrs->SetPosition(m_pstrX, m_pstrY, 4);
		}
	}
}

int Piscator::GetPstrX()
{
	return m_pstrX;
}