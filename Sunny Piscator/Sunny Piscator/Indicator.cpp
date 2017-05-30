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
void Indicator::HorPrintIndicator()  // when game object is moving
{
	for (int i = 1; i < m_Ind + 3; i++) 
	{
		/*
		* first column
		*/
		m_pCrs->SetPosition(m_PosX + i, m_PosY);
		m_pClr->SetBackground(White);
		cout << " ";

		/*
		* second column
		*/
		if (i == 1) 
		{
			m_pCrs->SetPosition(m_PosX + i, 1 + m_PosY);
			m_pClr->SetBackground(White);
			cout << " ";

			m_pCrs->SetPosition(m_PosX + i, 3 + m_PosY); // printing side message
			m_pClr->SetBackground(Black);
			cout << "0";
		}
		else if (i == m_Ind + 2)
		{
			m_pCrs->SetPosition(m_PosX + i, 1 + m_PosY);
			m_pClr->SetBackground(White);
			cout << " ";

			m_pCrs->SetPosition(m_PosX + i, 3 + m_PosY); // printing side message
			m_pClr->SetBackground(Black);
			cout << m_Ind;
		}

		else if (i != m_Ind + 2 || i != 1) {
			m_pCrs->SetPosition(m_PosX + i, 1 + m_PosY);
			m_pClr->SetBackground(Black);// thermometer level things
			cout << "|";
		}
		
		/*
		* third column
		*/
		m_pCrs->SetPosition(m_PosX + i, 2 + m_PosY);
		m_pClr->SetBackground(White);
		cout << " ";
	}

}
void Indicator::Report(string report) // shows message
{
	m_pCrs->SetPosition(m_PosX + 6, m_PosY + 6);
	m_pClr->SetBackground(Black);
	cout << report;
}

void Indicator::ReportTime(double time)  // shows time
{
	m_pCrs->SetPosition(m_PosX + 6, m_PosY + 7);
	m_pClr->SetBackground(Black);
	cout << time << " seconds";
}


void Indicator::VerTemp(int temp) // sets vertical limits
{
	for (int i = m_Ind + 1; i > m_Ind - temp + 1; i--) 
	{
		m_pCrs->SetPosition(m_PosX + 1, i + m_PosY);
		m_pClr->SetBackground(m_Indicalor);
		cout << " ";

		m_pCrs->SetPosition(m_PosX + 1, i + m_PosY);
		m_pClr->SetForeground(m_Back);
		cout << "_";
	}
}

void Indicator::HorTemp(int temp) // sets horizontal limits
{
	for (int i = 2; i < temp + 2; i++) 
	{
		m_pCrs->SetPosition(m_PosX + i, 1 + m_PosY);
		m_pClr->SetBackground(m_Indicalor);
		cout << " ";

		m_pCrs->SetPosition(m_PosX + i, 1 + m_PosY);
		m_pClr->SetForeground(m_Back);
		cout << "|";
	}
}