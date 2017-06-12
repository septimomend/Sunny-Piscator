/*
 * main.cpp - main fuction
 *
 * Sunny Piscator Game
 *
 * by septimomend
 * 12.06.2017     
 * 17:00 PM
*/
#include "stdafx.h" 
#include "Colour.h"
#include "Cursor.h"
#include "In_Out.h"
#include "Timer.h"
#include "Limn.h"
#include "Piscator.h"
#include "Snow.h"
#include "windows.h" 

using namespace std;

float _highscore = 0;

int main()
{
	// remove blinking cursor
	//
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.dwSize = 1;
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(hConsole, &CursorInfo);

	char input = '\0';

	Cursor crs;// setting controller objects
	ColourAppearance clr;

	Limn limn; // limn's class obj for drawing interface 
	limn.SetController(&crs, &clr); // gets cursor position and colour
	limn.LimnIntro(10, 10); // draw intro
	Sleep(7000); // pause
	system("cls"); // clears console
	limn.LimnHorizontal(0, 0, 61); // first horizontal border
	limn.LimnHorizontal(0, 4, 40); // second
	limn.LimnHorizontal(0, 34, 61); // third
	limn.LimnInstructions(43, 2); // draws instructions
	limn.LimnTitle(13, 2); // draws game's title
	limn.LimnVertical(0, 1, 33); // first vertical border
	limn.LimnVertical(40, 1, 33); // second
	limn.LimnVertical(60, 1, 33); // third

	Piscator pstr; // piscator
	pstr.SetController(&crs, &clr); // sets default position and view for piscator
	Snow snowflake; // snow
	snowflake.SetController(&crs, &clr); // sets default position and view for snowflake

	// game cycle until player doesn't exit
	//
	while (1)
	{

		limn.PlayGame(); // start game
		while (input != 'g' && input != 'e')
		{
			io >> input;
			// if hitted 'e' then exit
			//
			if (input == 'e')
				exit(1);
		}
		snowflake.FillArray(); // fill array of snowflakes full of 0
		Timer timer; // timer
		timer.Start(); // start timer
		float totalTime = 0; // 
		float time = 0; 
		int pos1, pos2;
		int loopCount = 0;
		int start = 1; // for pause
		int score = 20; // sets default scores when game is begun
		Timer gameTimer; // time of game's cycle


		while (score > 0)
		{
			while (!_kbhit() && score > 0) // until key is not pressed and score is > 0
			{
				time = timer.CurrentTime();// reads time since game started

				if (time >= 1) // when true run the loop
				{
					pos1 = pstr.GetPstrX(); // position of piscator
					pos2 = snowflake.LeastSnowflake(); // position of last snowflake
					if (loopCount > 25) // in order to not to catch snowflakes in advance. Only when it will be on upper line of piscator
					{ 
						// if the piscator X position is in the same location as least
						// snowflake in the array add 2 points to the score
						//
						if (start == 1) // start is set true
						{
							gameTimer.Start(); // game timer is started
							start++; // add 1 in order to game's timer will not be reloaded 
						}
						if (pos1 == pos2 || pos1 + 1 == pos2) // if piscator catched the snowflake
							score += 2; // add 2 points
						else
							score -= 2; // subtract 2 points if missed
					}
					totalTime = gameTimer.CurrentTime(); // remember time
					limn.LimnScores(score, totalTime, _highscore); // draw time, scores and hightscore
					snowflake.AddSnowflake(); // add snowflake to array
					snowflake.ArrayShift(); // shift array down
					snowflake.ShowSnow(); // displays snowflake from array
					snowflake.ArrayLevel();// remove snowflake from last level of array
					time = 0; // reset time to 0 so loop timer will start again
					timer.Stop(); // stop timer
					timer.Reset(); // reset timer
					timer.Start(); // start timer
					loopCount++; //add 1 to loop count each time if loop runs
				}
			}
			if (score > 0)
			{
				io >> input; // getting keyboard input for the game
				if (input == 'p') // pause game
					io.Get();
				if (input == 'e') // exit
				{
					cout << "\n\n\n\n"; // for "Press any key to continue..."
					limn.LimnDefault();
					exit(1);
				}
			}
			pstr.Move(input); // moving piscator to left or right

		}
		if (totalTime > _highscore) // high score updated if new score is higher
		{
			_highscore = totalTime;
			limn.LimnScores(score, totalTime, totalTime);
		}

		limn.GameOver(); // display game over message
		io.Get();
	}
	return 0;
}