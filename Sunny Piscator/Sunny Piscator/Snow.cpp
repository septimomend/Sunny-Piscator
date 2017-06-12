// Snow.cpp - definition of class, placed in Snow.h
#include "stdafx.h"
#include "Snow.h"

using namespace std;

Snow::Snow() : Limn() // cstr
{
	m_Back = Aqua;
	m_Fore = White;
}

void Snow::SetController(Cursor* crs, ColourAppearance* clr) // sets cursor and colour
{
	m_pCrs = crs;
	m_pClrLimn = clr;
}

void Snow::SetColours(colour back_clr, colour fore_clr) // sets background colour
{
	m_Back = back_clr;
	m_Fore = fore_clr;
}

void Snow::AddSnowflake() // add item (snowflake) to array
{
	// add a snowflake randomly
	//
	Randomizer random;
	random.SetBorders(0, 19);

	static unsigned int sSeed = 5323;
	sSeed = (8253729 * sSeed + 23960403);

	m_SnowArr[sSeed % 38][1] = (char)15; //adding random snowflake to first line 
}

void Snow::ShowSnow() // displays snow
{
	for (int i = 0; i < 38; i++) // all rows
	{
		for (int j = 0; j < 28; j++) // all columns
		{
			m_pClrLimn->SetBackground(m_Back); // setting foreground colours
			m_pClrLimn->SetForeground(White); // setting background colours
			m_pCrs->SetPosition(2 + i, 1 + j, 4); //setting correct position
			cout << m_SnowArr[i][j];
		}
	}
}

void Snow::FillArray() // fills the array
{
	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			m_SnowArr[i][j] = ' ';
		}
	}
}
int Snow::LeastSnowflake() // check a least snowflake 
{
	//Search thru the last line for the snowflake, return position
	for (int j = 0; j < 38; j++)
	{
		if (m_SnowArr[j][27] == (char)15)// checking to see if it contains a snowflake
		{
			return j + 2; // return star position
		}
	}
}

void Snow::ArrayShift() // shifts array index down one so that the snowflake look like they are falling
{
	// shift row down 
	// algorithm copies top last row to row above
	//
	for (int i = 0; i < 38; i++)
	{
		for (int j = 28; j > -1; j--)
		{
			if (m_SnowArr[i][j] == (char)15)
			{
				m_SnowArr[i][j] = ' ';
				m_SnowArr[i][j + 1] = (char)15;
			}
		}
	}
}

void Snow::ArrayLevel()  // last line of snowflakes
{
	for (int i = 0; i < 38; i++)
	{
		if (m_SnowArr[i][28] == (char)15)
			m_SnowArr[i][28] = ' ';
	}
}