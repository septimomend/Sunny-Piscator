// Limn.h - header file contains declaration of class for limning the border of game and game interface
#ifndef LIMN_H
#define LIMN_H
#include "stdafx.h"
#include "Colour Controller.h"
#include "Colour.h"
#include "Cursor.h"

class Limn : public ColourController
{
public:
	Limn(); // cstr 1
	Limn(Cursor* crs, ColourAppearance* clr); // cstr 2
	Limn(int x, int y, Cursor* crs, ColourAppearance* clr); // cstr 3
	void SetController(Cursor* crs, ColourAppearance* clr); // sets cursor and colour
	void SetColours(colour back_clr, colour fore_clr); // sets background colour
	void LimnInstructions(); // draws game instructions
	void LimnInstructions(int x, int y);
	void LimnName(int x, int y);
	void LimnIntro(int x, int y);
	void LimnHorizontal(int x, int y, int howlong); // horizontal limits
	void LimnVertical(int x, int y, int howlong); // draws vertical limits
	void LimnScores(int score, float time, float highscore); // display scores
	void PlayGame(); // limns action to play game
	void GameOver(); // shows message when game is over
	void LimnHighscore(float highscr); // show hightscore

protected:
	colour m_Back, m_Fore; 
	ColourAppearance* m_pClrLimn;
};

#endif // !LIMN_H
