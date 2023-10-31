#pragma once
#include "Fraction.h"
#include <numeric>		//gcd()

using std::gcd;
using std::to_string;

class DecimalFormat {
private:
	string _decimalSeparator;
	int _precision;
public:
	DecimalFormat();
	DecimalFormat(string, int);
	void setSeparator(string);
	void setPrecision(int);
	string separator();
	int precision();
};

class FractionToMixedConverter {
public:
	string convert(Fraction);
};

class FractionToDecimalConverter {
private:
	DecimalFormat _config;
public:
	FractionToDecimalConverter();
	FractionToDecimalConverter(DecimalFormat);
	string convert(Fraction);
};

class FractionToPercentageConverter {
private:
	DecimalFormat _config;
public:
	FractionToPercentageConverter();
	FractionToPercentageConverter(DecimalFormat);
	string convert(Fraction);
};