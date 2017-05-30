// Indicator.h - header file contains declaration of class for describing counter
#ifndef INDICATOR_H
#define INDICATOR_H
#include "stdafx.h"
#include "Colour.h"
#include "Cursor.h"

class Indicator
{
public:
	Indicator(int indSize, int x, int y); // cstr
	void SetPosition(int x, int y); // sets coordinate position
	void SetController(Cursor *crs, ColourAppearance* clr);  // sets cursor and colour
	void SetColours(colour backClr, colour indClr);
	void VerPrintIndicator(); // static columns
	void HorPrintIndicator(); // when game object is moving
	void ReportTime(double time); // shows time
	void Report(std::string report); // shows message
	void VerTemp(int temp); // sets vertical limits
	void HorTemp(int temp); // sets horizontal limits

private:
	int m_PosX, m_PosY, m_Ind, m_Temp;
	double m_Time;
	std::string m_Report;
	Cursor* m_pCrs;
	ColourAppearance* m_pClr;
	colour m_Back, m_Indicalor;
};

#endif // !INDICATOR_H
