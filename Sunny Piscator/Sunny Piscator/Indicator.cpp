// Indicator.cpp - definition of class, placed in Indicator.h
#include "stdafx.h"
#include "Indicator.h"

using namespace std;

Indicator::Indicator(int indSize, int x, int y) // cstr
{ 
	m_Ind = indSize;
	m_PosX = x;
	m_PosY = y; 
	m_pCrs = 0; 
	m_pClr = 0;
}

void Indicator::SetPosition(int x, int y)  // sets coordinate position
{ 
	m_PosX = x;
	m_PosY = y;
}

void Indicator::SetController(Cursor *crs, ColourAppearance* clr)   // sets cursor and colour
{ 
	m_pCrs = crs; 
	m_pClr = clr; 
}

void Indicator::SetColours(colour backClr, colour indClr) 
{ 
	m_Back = backClr;
	m_Indicalor = indClr; 
}

void Indicator::VerPrintIndicator() // static columns
{
	for (int i = 1; i < m_Ind + 3; i++) 
	{
		/*
		* first column
		*/
		m_pCrs->SetPosition(m_PosX, i + m_PosY);
		m_pClr->SetBackground(White);
		cout << " ";

		/*
		* second column
		*/
		if (i == 1) 
		{
			m_pCrs->SetPosition(m_PosX + 1, i + m_PosY);
			m_pClr->SetBackground(White);
			cout << " ";

			m_pCrs->SetPosition(m_PosX + 3, i + m_PosY); // printing side message
			m_pClr->SetBackground(Black);
			cout << " " << m_Ind;
		}
		else if (i == m_Ind + 2) 
		{
			m_pCrs->SetPosition(m_PosX + 1, i + m_PosY);
			m_pClr->SetBackground(White);
			cout << " ";

			m_pCrs->SetPosition(m_PosX + 3, i + m_PosY); // printing side message
			m_pClr->SetBackground(Black);
			cout << " 0";
		}
		else if (i != m_Ind + 2 || i != 1) 
		{
			m_pClr->SetBackground(Black); // thermometer level things
			cout << "_";
		}

		/*
		* third column
		*/
		m_pCrs->SetPosition(m_PosX + 2, i + m_PosY);
		m_pClr->SetBackground(White);
		cout << " ";
	}

}
void Indicator::HorPrintIndicator() 
{
	for (int i = 1; i < m_Ind + 3; i++) 
	{
		/*
		* first column
		*/
		m_pCrs->setPosition(xpos + i, ypos);
		m_pClr->setBackground(White);
		cout << " ";

		if (i == 1) {
			m_pCrs>setPosition(xpos + i, 1 + ypos);
			m_pClr->setBackground(White);
			cout << " ";

			m_pCrs->setPosition(xpos + i, 3 + ypos); // printing side message
			m_pClrx->setBackground(Black);
			cout << "0";
		}
		else if (i == ms + 2) {
			m_pCrs->setPosition(xpos + i, 1 + ypos);
			m_pClrx->setBackground(White);
			cout << " ";

			m_pCrs->setPosition(xpos + i, 3 + ypos); // printing side message
			m_pClrx->setBackground(Black);
			cout << ms;
		}

		else if (i != ms + 2 || i != 1) {
			m_pCrs->setPosition(xpos + i, 1 + ypos);
			m_pClrx->setBackground(Black);// thermomerter level things
			cout << "|";
		}
		//third coloum
		m_pCrs->setPosition(xpos + i, 2 + ypos);
		m_pClrx->setBackground(White);
		cout << " ";
	}

}
void MeterClass::Message(string message) {
	m_pCrs->setPosition(xpos + 6, ypos + 6);
	m_pClrx->setBackground(Black);
	cout << message;

}

void MeterClass::timeMessage(double time) {
	m_pCrs->setPosition(xpos + 6, ypos + 7);
	m_pClrx->setBackground(Black);
	cout << time << " Seconds";

}


void MeterClass::vTemp(int temp) {
	for (int i = ms + 1; i > ms - temp + 1; i--) {
		m_pCrs->setPosition(xpos + 1, i + ypos);
		m_pClrx->setBackground(meter);
		cout << " ";
		m_pCrs->setPosition(xpos + 1, i + ypos);
		m_pClrx->setForeground(back);
		cout << "_";
	}
}

void MeterClass::hTemp(int temp) {
	for (int i = 2; i < temp + 2; i++) {
		m_pCrs->setPosition(xpos + i, 1 + ypos);
		m_pClrx->setBackground(meter);
		cout << " ";
		m_pCrs->setPosition(xpos + i, 1 + ypos);
		m_pClrx->setForeground(back);
		cout << "|";
	}
}