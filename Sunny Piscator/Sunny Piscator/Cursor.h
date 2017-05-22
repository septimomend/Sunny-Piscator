// Cursor.h - header file contains definition of class for controlling cursor
#ifndef CURSOR_H
#define CURSOR_H
#include "stdafx.h"

class Cursor
{
public:
	Cursor(); // cstr
	void SetPosition(short x, short y); // sets cursor's position
	short GetX(); // returns X coordinate
	short GetY(); // returns Y coordinate
	void Default(); // clears all parameters and sets default position 

private:
	HANDLE m_hOut; // handle is what function working with. Ie this is descriptor of object 
				   /*************************************
				   * http://cppstudio.com/en/post/9489/ *
				   **************************************/
	CONSOLE_SCREEN_BUFFER_INFO m_ConsBuffInfo; // contains information about a console screen buffer
											   /**********************************************************************************
											   * https://msdn.microsoft.com/ru-ru/library/windows/desktop/ms682093(v=vs.85).aspx *
											   ***********************************************************************************/
	COORD m_coord; // Defines the coordinates of a character cell in a console screen buffer.
				   // The origin of the coordinate system (0,0) is at the top, left cell of the buffer.
				   /**********************************************************************************
				   * https://msdn.microsoft.com/ru-ru/library/windows/desktop/ms682119(v=vs.85).aspx *
				   ***********************************************************************************/
	void SetConsole();
};

#endif // CURSOR_H