#include "Fraction.h"
#include "FractionKeyboardProvider.h"
#include "FractionConverter.h"

int main()
{
	FractionKeyboardProvider provider;
	Fraction f = provider.next();

	cout << "Your fraction is: " << f.toString() << endl;

	FractionToMixedConverter converterFTM;
	string mixedFraction = converterFTM.convert(f);
	cout << "Fraction to Lowest term & mixed: " << mixedFraction << endl;

	DecimalFormat formatD(".", 3);
	FractionToDecimalConverter converterFTD(formatD);
	string decimal = converterFTD.convert(f);
	cout << "Fraction to Decimal: " << decimal << endl;

	DecimalFormat formatP(".", 1);
	FractionToPercentageConverter converterFTP(formatP);
	string percentage = converterFTP.convert(f);
	cout << "Fraction to Percentage: " << percentage << endl;

	return 0;
}