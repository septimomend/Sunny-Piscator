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
	// sketch
	// REDO
	for (int j = 0; j < 20; ++j)
	{
		for (int i = 0; i < 30; i++) 
		{
			m_pClrLimn->SetBackground(Aqua);	// setting background colours
			m_pCrs->SetPosition(j + 41, i + 1);	// setting foreground colours
			cout << " ";
		}
	}
	m_pCrs->SetPosition(x, y);
	m_pClrLimn->SetForeground(Blue);
	cout << "Sunny Piscat" << char(1) << "r";
	m_pCrs->SetPosition(x, y + 1);
	m_pClrLimn->SetForeground(White);
	cout << "by septimomend";
	m_pCrs->SetPosition(x, y + 3);
	cout << "(Chapkailo I.)";
	m_pCrs->SetPosition(x, y + 4);
	m_pClrLimn->SetForeground(Blue);

	m_pCrs->SetPosition(x, y + 6);
	m_pClrLimn->SetForeground(Yellow);
	cout << "'p' to pause";
	m_pCrs->SetPosition(x, y + 7);
	cout << "Esc to exit";
	m_pCrs->SetPosition(x, y + 8);
	m_pClrLimn->SetForeground(White);
	cout << "Catch + 2";
	m_pCrs->SetPosition(x, y + 9);
	m_pClrLimn->SetForeground(White);
	cout << "Miss - 2";
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
			std::cout << " ";
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
			std::cout << " ";
		}
	}
}

void Limn::LimnScores(int score, float time, float highscore) // display scores and time
{
	// sketch
	// REDO
	m_pCrs->SetPosition(45, 20);
	m_pClrLimn->SetBackground(Aqua);
	m_pClrLimn->SetForeground(Yellow);
	cout << "Score: " << score;
	m_pCrs->SetPosition(45, 21);
	m_pClrLimn->SetBackground(Aqua);
	m_pClrLimn->SetForeground(Yellow);
	cout << "Time: " << time;
	m_pCrs->SetPosition(45, 22);
	m_pClrLimn->SetBackground(Aqua);
	m_pClrLimn->SetForeground(Yellow);
	cout << "Best: " << highscore;
}

void Limn::PlayGame() // limns action to play game
{
	// sketch
	// REDO
	m_pCrs->SetPosition(13, 15);
	m_pClrLimn->SetBackground(Black);
	m_pClrLimn->SetForeground(Yellow);
	cout << "Press 's' to Play!";
}

void Limn::GameOver() // shows message when game is over
{
	// sketch
	// REDO
	m_pCrs->SetPosition(13, 15);
	m_pClrLimn->SetBackground(Black);
	m_pClrLimn->SetForeground(Yellow);
	cout << "G" << char(15) << "me " << char(2) << "ver";
}

void Limn::LimnHighscore(float highscr) // show hightscore
{
	// TODO
}