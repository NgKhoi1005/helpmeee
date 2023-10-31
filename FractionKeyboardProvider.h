#include "Fraction.h"
#include <iostream>
#include <regex>

using std::cin, std::cout, std::endl;
using std::regex, std::regex_match;

class FractionKeyboardProvider {
public:
	static Fraction next();
};