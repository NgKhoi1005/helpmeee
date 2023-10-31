#include "Fraction.h"


Fraction::Fraction()
{
	_num = 0;
	_den = 1;
}
Fraction::Fraction(int num, int den)
{
	_num = num;
	_den = den;
}
string Fraction::toString()
{
	stringstream builder;

	builder << _num << "/" << _den;

	string result = builder.str();
	return result;
}

int Fraction::numerator()
{
	return _num;
}
int Fraction::denominator()
{
	return _den;
}
void Fraction::setNumerator(int value)
{
	_num = value;
}
void Fraction::setDenominator(int value)
{
	_den = value;
}