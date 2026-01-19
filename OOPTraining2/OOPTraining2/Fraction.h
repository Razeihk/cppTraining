#pragma once
class Fraction
{
public:
	Fraction();
	Fraction(int a, int b = 1);

	void DisplayFraction() const;
	int GetNumerator() const;
	int GetDenominator() const;

private:
	int m_Numerator = 0;
	int m_Denominator = 0;
};