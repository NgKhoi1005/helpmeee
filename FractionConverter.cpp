#include "FractionConverter.h"

#pragma region NumberFormat
DecimalFormat::DecimalFormat()
{

}
DecimalFormat::DecimalFormat(string separator, int precision)
{
	_decimalSeparator = separator;
	_precision = precision;
}
string DecimalFormat::separator()
{
	return _decimalSeparator;
}
int DecimalFormat::precision()
{
	return _precision;
}
void DecimalFormat::setSeparator(string sep)
{
	_decimalSeparator = sep;
}
void DecimalFormat::setPrecision(int pre)
{
	_precision = pre;
}
#pragma endregion


#pragma region FractionToMixed
string FractionToMixedConverter::convert(Fraction f)
{
	int num = f.numerator(), den = f.denominator();
	int common = gcd(num, den);
	num /= common;	den /= common;

	int wholeNum = 0;
	while (num >= den)
	{
		num -= den;
		wholeNum++;
	}

	stringstream builder;
	if (wholeNum != 0)
	{
		builder << wholeNum << " ";
	}
	if (num != 0)
	{
		builder << num << "/" << den;
	}

	string result = builder.str();
	return result;

}
#pragma endregion


#pragma region FractionToDecimal
FractionToDecimalConverter::FractionToDecimalConverter()
{

}
FractionToDecimalConverter::FractionToDecimalConverter(DecimalFormat other)
{
	_config = other;
}
string FractionToDecimalConverter::convert(Fraction f)
{
	float frac = (float)f.numerator() / f.denominator();
	for (int i = 0; i < _config.precision(); i++)
	{
		frac *= 10;
	}

	int decNum = (int)frac;
	string result = to_string(decNum);
	int len = result.length();
	result.insert(len - _config.precision(), _config.separator());

	if (to_string(result[0]) == _config.separator())
	{
		result = "0" + result;
	}

	return result;
}
#pragma endregion


#pragma region FractionToPercentage
FractionToPercentageConverter::FractionToPercentageConverter()
{

}
FractionToPercentageConverter::FractionToPercentageConverter(DecimalFormat other)
{
	_config = other;
}
string FractionToPercentageConverter::convert(Fraction f)
{
	float frac = (float)f.numerator() / f.denominator();
	for (int i = 0; i < _config.precision(); i++)
	{
		frac *= 10;
	}
	frac *= 100;

	string result = to_string((int)frac);
	int len = result.length();
	result.insert(len - _config.precision(), _config.separator());


	result += "%";
	return result;
}
#pragma endregion