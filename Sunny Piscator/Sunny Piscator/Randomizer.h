// Randomaizer.h - header file contains definition of class for randomizing in certain borders
#ifndef RANDOMIZER_H
#define RANDOMIZER_H

class Randomizer
{
public:
	Randomizer();
	void SetBorders(double lower, double upper);
	int Get();
	int GetLast();

protected:
	int m_Value;

private:
	int m_Lower, m_Upper;
};

#endif // !RANDOMIZER_H
