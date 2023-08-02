#include <iostream>
#include "mystring.h"
#include <string>
using namespace std;


int main()
{
	Cpang::String cst("abcdefghijklmn");
	Cpang::String cs2("3344");
	Cpang::String c("@2");
	cst.insert(3, "hjk");

	Cpang::String d = cs2 + cst;

	//cout << d + c + "98567" + cs2 + "77oopp" << endl;
	//puts((const char*)cst);
	cout << cst.substr(cst.find('f')) << endl;
	return 0;
}