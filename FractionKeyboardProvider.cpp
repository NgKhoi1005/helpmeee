#include "FractionKeyboardProvider.h"

Fraction FractionKeyboardProvider::next()
{
	string buffer;
	regex FractionPattern("\\d+\/\\d+");

	bool check = false;
	int num, den;

	while (!check)
	{
		cout << "Enter a fraction: ";
		getline(cin, buffer);
		check = regex_match(buffer, FractionPattern);
		if (check == false)
		{
			cout << endl << "Invalid format. Try again!" << endl;
			continue;
		}
			
		std::istringstream in(buffer);
		string tmp;
		getline(in, tmp, '\/');
		num = stoi(tmp);
		getline(in, tmp);
		den = stoi(tmp);

		if (den == 0)
		{
			cout << endl << "Divided by zero. Try again!" << endl;
			check = false;
		}
		else
		{
			check = true;
		}
	}

	Fraction result(num, den);
	return result;
}