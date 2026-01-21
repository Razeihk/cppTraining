#include "Fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction()
	:m_Numerator(0), m_Denominator(1)
{
	
}

Fraction::Fraction(int num, int den)
	: m_Numerator(num), m_Denominator(den)
{
}

void Fraction::DisplayFraction(ostream& Stream) const
{
	if (m_Denominator == 1)
	{
		Stream << m_Numerator;
	}
	else if (m_Denominator != 0)
	{
		Stream << m_Numerator << "/" << m_Denominator;
	}
	else
	{
		Stream << "ERROR: Denominator can't be 0";
	}
	 
}


// GETTERS

int Fraction::GetNumerator() const
{
	return m_Numerator;
}

int Fraction::GetDenominator() const
{
	return m_Denominator;
}


// OPERATORS

Fraction& Fraction::operator*=(Fraction const& other)
{
	m_Numerator *= other.m_Numerator;
	m_Denominator *= other.m_Denominator;
	return *this;
}

bool Fraction::IsEqual(Fraction const& other) const
{
	return m_Numerator == other.m_Numerator && m_Denominator == other.m_Denominator;
}

Fraction& operator*(Fraction const& a, Fraction const& b)
{
	Fraction Result(a);
	Result *= b;
	return Result;
	}

std::ostream& operator<<(std::ostream& Stream, Fraction const& Frac)
{
	Frac.DisplayFraction(Stream);
	return Stream;
}

bool operator==(Fraction const& a, Fraction const& b)
{
	return a.IsEqual(b);
}
