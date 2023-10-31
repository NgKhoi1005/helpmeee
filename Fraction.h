#pragma once
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

class Fraction {
private:
	int _num;
	int _den;

public:
	Fraction();
	Fraction(int, int);
	string toString();
public:
	int numerator();
	int denominator();
	void setNumerator(int);
	void setDenominator(int);

};
