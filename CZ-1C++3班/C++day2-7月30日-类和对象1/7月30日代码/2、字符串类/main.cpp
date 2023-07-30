#include <iostream>
#include "cstring.h"
using namespace std;

int main()
{
	Cpang::string s("Cpanglaoshi");
	Cpang::string s2(s, 5, 9);

	Cpang::string s3 = s2;

	const Cpang::string s4;

	(s4 + s3).printString();

	//s3.printString();
	return 0;
}