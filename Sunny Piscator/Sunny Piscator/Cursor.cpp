// Cursor.cpp - declaration of class, placed in Cursor.h
#include "stdafx.h"
#include "Cursor.h"


Cursor::Cursor()
{
	m_hOut = GetStdHandle(STD_OUTPUT_HANDLE); // gets a handle for the output device
	GetConsoleScreenBufferInfo(m_hOut, &m_ConsBuffInfo); // gets info about output device and save adress of this info 
														 // through reference m_ConsBuffInfo
	m_coord = m_ConsBuffInfo.dwCursorPosition; // dwCursorPosition - a COORD structure that contains the column and 
											   // row coordinates of the cursor in the console screen buffer.
}

void Cursor::SetPosition(short x, short y)
{
	m_coord.X = x; // set X position
	m_coord.Y = y; // set Y position
	SetConsole();
}

short Cursor::GetX()
{
	GetConsoleScreenBufferInfo(m_hOut, &m_ConsBuffInfo); // gets info about output device and save adress of this info 
														 // through reference m_ConsBuffInfo
	m_coord = m_ConsBuffInfo.dwCursorPosition; // dwCursorPosition - a COORD structure that contains the column and 
											   // row coordinates of the cursor in the console screen buffer.
	return m_coord.X; // return X coordinate
}

short Cursor::GetY()
{
	GetConsoleScreenBufferInfo(m_hOut, &m_ConsBuffInfo); // gets info about output device and save adress of this info 
														 // through reference m_ConsBuffInfo
	m_coord = m_ConsBuffInfo.dwCursorPosition; // dwCursorPosition - a COORD structure that contains the column and 
											   // row coordinates of the cursor in the console screen buffer.
	return m_coord.Y; // return Y coordinate
}

void Cursor::Default()
{
	COORD startPoint = { 0, 0 };
	if (!GetConsoleScreenBufferInfo(m_hOut, &m_ConsBuffInfo)) // no info
		return;
	DWORD coordSize = m_ConsBuffInfo.dwSize.X * m_ConsBuffInfo.dwSize.Y; // size of X and Y coord
																		 // dwSize - a COORD structure that contains the size of the console
																		 // screen buffer, in character columns and rows.
	DWORD symbols;
	if (!FillConsoleOutputCharacter(m_hOut, (TCHAR) ' ', coordSize, startPoint, &symbols)) // writes a character to the console screen
																						   // buffer a specified number of times, beginning
																						   // at the specified coordinates
																							/**********************************************************************************
																							* https://msdn.microsoft.com/ru-ru/library/windows/desktop/ms682663(v=vs.85).aspx *
																							***********************************************************************************/
		return;
											// Writes a character string to a console screen buffer beginning at the current cursor location.
	//															|
	if (!FillConsoleOutputAttribute(m_hOut, m_ConsBuffInfo.wAttributes, coordSize, startPoint, &symbols)) // Sets the character attributes
																										  // for a specified number of character
																										  // cells, beginning at the specified
																										  // coordinates in a screen buffer.
																										  /**********************************************************************************
																										  * https://msdn.microsoft.com/ru-ru/library/windows/desktop/ms682662(v=vs.85).aspx *
																										  ***********************************************************************************/
		return;

	SetConsoleCursorPosition(m_hOut, startPoint); // Sets the cursor position in the specified console screen buffer.
}