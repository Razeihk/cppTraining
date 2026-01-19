#include "Fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction()
{
	
}


Fraction::Fraction(int a, int b)
	: m_Numerator(a), m_Denominator(b)
{
}

void Fraction::DisplayFraction() const
{
	cout << m_Numerator << "/" << m_Denominator << endl;
}

int Fraction::GetNumerator() const
{
	return m_Numerator;
}

int Fraction::GetDenominator() const
{
	return m_Denominator;
}

