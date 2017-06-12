// Limn.cpp - definition of class, placed in Limn.h
#include "stdafx.h"
#include "Limn.h"

using namespace std;

Limn::Limn() : ColourController() // cstr 1 // set default colour
{
	m_pClrLimn = 0; // nullptr
	m_Back = White;
	m_Fore = White;
}

Limn::Limn(Cursor* crs, ColourAppearance* clr) // cstr 2
{
	// TODO
}

Limn::Limn(int x, int y, Cursor* crs, ColourAppearance* clr) // cstr 3
{
	// TODO
}

void Limn::SetController(Cursor* crs, ColourAppearance* clr) // sets cursor and colour
{
	m_pCrs = crs; 
	m_pClrLimn = clr; 
}

void Limn::SetColours(colour back_clr, colour fore_clr) // sets background colour
{
	m_Back = back_clr; 
	m_Fore = fore_clr;
}

void Limn::LimnInstructions() // draws game instructions
{
	// TODO
}

void Limn::LimnInstructions(int x, int y)
{
	for (int j = 0; j < 40; ++j)
	{
		for (int i = 0; i < 29; i++) 
		{
			m_pClrLimn->SetBackground(Aqua); // setting background colours
			m_pCrs->SetPosition(j + 1, i + 5);
			cout << " ";
		}
	}

	for (int j = 0; j < 20; ++j)
	{
		for (int i = 0; i < 33; i++) 
		{
			m_pClrLimn->SetBackground(Blue); // setting background colours
			m_pCrs->SetPosition(j + 41, i + 1);
			cout << " ";
		}
	}

	m_pCrs->SetPosition(x, y + 1);
	m_pClrLimn->SetForeground(White); // setting foreground colours
	cout << "by septimomend";
	m_pCrs->SetPosition(x, y + 2);
	m_pClrLimn->SetForeground(Black);
	cout << "(Chapkailo I.)";
	m_pCrs->SetPosition(x, y + 4);
	m_pClrLimn->SetForeground(Yellow);

	m_pCrs->SetPosition(x, y + 6);
	m_pClrLimn->SetForeground(Yellow);
	cout << "'p' - pause";
	m_pCrs->SetPosition(x, y + 7);
	cout << "'e' - exit";
	m_pCrs->SetPosition(x - 1, y + 9);
	m_pClrLimn->SetForeground(White);
	cout << "Catched - score+2";
	m_pCrs->SetPosition(x - 1, y + 10);
	m_pClrLimn->SetForeground(White);
	cout << "Missed  - score-2";
}

void Limn::LimnTitle(int x, int y)
{
	for (int j = 0; j < 40; ++j)
	{
		for (int i = 0; i < 3; i++) 
		{
			m_pClrLimn->SetBackground(Aqua); // setting background colours
			m_pCrs->SetPosition(j + 1, i + 1);
			cout << " ";
		}
	}
	m_pCrs->SetPosition(x, y);
	m_pClrLimn->SetForeground(White); // setting foreground colours
	cout << "Sunny Piscat";
	m_pClrLimn->SetForeground(Yellow);
	cout << char(2);
	m_pClrLimn->SetForeground(White);
	cout << "r";
}

void Limn::LimnIntro(int x, int y)
{
	for (int j = 0; j < 80; ++j)
	{
		for (int i = 0; i < 40; i++) 
		{
			m_pClrLimn->SetBackground(Aqua); // setting background colours
			m_pCrs->SetPosition(j, i);
			cout << " ";
		}
	}
	m_pCrs->SetPosition(x, y);
	m_pClrLimn->SetForeground(White); // setting foreground colours
	cout << "              Welcome to the Sunny Piscator!" << endl;
	m_pCrs->SetPosition(x, y + 2);
	m_pClrLimn->SetForeground(White);
	cout << "                 Do you love to eat snow?";
	m_pCrs->SetPosition(x, y + 3);
	m_pClrLimn->SetForeground(White);
	cout << "So let's check how long you can catch snowflakes by mouth!" << endl;
	m_pCrs->SetPosition(x, y + 25);
	m_pClrLimn->SetForeground(White);
	cout << "\t\t\t\tby septimomend";
	m_pClrLimn->SetForeground(Black);
	cout << " (Chapkailo I.)" << std::endl;
	m_pClrLimn->SetBackground(Black);
}

void Limn::LimnHorizontal(int x, int y, int howlong) // horizontal limits
{
	if (m_pClrLimn) // checking pointer is initlized
	{
		for (int i = 0; i < howlong; i++) 
		{
			m_pClrLimn->SetBackground(m_Back); // setting background colours
			m_pClrLimn->SetForeground(m_Fore); // setting foreground colours
			m_pCrs->SetPosition(i + x, y);
			cout << " ";
		}
	}
}

void Limn::LimnVertical(int x, int y, int howlong) // draws vertical limits
{
	if (m_pClrLimn) // checking pointer is initlized
	{
		for (int i = 0; i < howlong; i++) 
		{
			m_pClrLimn->SetBackground(m_Back); // setting background colours
			m_pClrLimn->SetForeground(m_Fore); // setting foreground colours
			m_pCrs->SetPosition(x, i + y);
			cout << " ";
		}
	}
}

void Limn::LimnScores(int score, float time, float highscore) // display scores and time
{
	m_pCrs->SetPosition(45, 20);
	m_pClrLimn->SetBackground(Blue); // setting background colours
	m_pClrLimn->SetForeground(Red);	 // setting foreground colours
	cout << "Score: " << score << "   ";
	m_pCrs->SetPosition(45, 21);
	m_pClrLimn->SetBackground(Blue);
	m_pClrLimn->SetForeground(Red);
	cout << "Time:  " << time;
	m_pCrs->SetPosition(45, 22);
	m_pClrLimn->SetBackground(Blue);
	m_pClrLimn->SetForeground(Red);
	cout << "Best:  " << highscore;
}

void Limn::PlayGame() // limns action to play game
{
	m_pCrs->SetPosition(12, 20);
	m_pClrLimn->SetBackground(Aqua);
	m_pClrLimn->SetForeground(Yellow);
	cout << "Press 'g' to go!";
	cout << endl << endl << "\t";
}

void Limn::GameOver() // shows message when game is over
{
	m_pCrs->SetPosition(15, 20);
	m_pClrLimn->SetBackground(Aqua);
	m_pClrLimn->SetForeground(Yellow);
	cout << "Game " << char(1) << "ver!";
}

void Limn::LimnHighscore(float highscr) // show hightscore
{
	// TODO
}

void Limn::LimnDefault()
{
	m_pCrs->SetPosition(5, 20);
	m_pClrLimn->SetBackground(Aqua);
	m_pClrLimn->SetForeground(Yellow);
}