#pragma once
#include <iostream>

class Fraction
{
public:
	Fraction();
	Fraction(int a, int b = 1);

	void DisplayFraction(std::ostream& Stream) const;
	int GetNumerator() const;
	int GetDenominator() const;

	Fraction& operator*=(Fraction const& other);
	bool IsEqual(Fraction const& other) const;
		

private:
	int m_Numerator = 0;
	int m_Denominator = 0;
};


// OPERATORS

Fraction& operator*(Fraction const& a, Fraction const& b);
std::ostream& operator<<(std::ostream& Stream, Fraction const& Frac);
bool operator==(Fraction const& a, Fraction const& b);