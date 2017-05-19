// In_Out.h - header file contained definition of class for working with keyboard
#ifndef IN_OUT_H
#define IN_OUT_H
#include "stdafx.h"

static class sInOut
{
public:
	sInOut();
	void YesResponse();
	void NoResponse();
	bool GetResponse();
	bool Waiting();
	void Get();
	sInOut& operator >> (int& var);
	sInOut& operator >> (char& var);
private:
	bool m_Response;
	char m_Stored;
} io;

#endif // IN_OUT_H