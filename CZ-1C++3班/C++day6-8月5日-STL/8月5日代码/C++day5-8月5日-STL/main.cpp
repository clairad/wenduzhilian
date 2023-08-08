#include <iostream>
#include <string>
#include "String.hpp"
using namespace std;

int main()
{
	Cpang::String s1;
	cin >> s1;

	int i;
	int start = 0;
	int end;
	for (i = 0; i < s1.size(); i++)
	{
		if (s1[i] == ' ')
		{
			end = i;
			Cpang::reverse(s1.begin() + start, s1.begin() + end);
			start = i + 1;
		}
	}
	Cpang::reverse(s1.begin() + start, s1.end());
	Cpang::reverse(s1.begin(), s1.end());

	cout << s1;
	return 0;
}

int teststring()
{
	Cpang::String s1("CpangCpangCpang");
	Cpang::String s2(10, 'x');
	//Cpang::String s3(s1, 3);
	Cpang::String s4 = s2;

	//s1.insert(s1.find('a'), 2, 'b');
	//s1.erase(s1.find('b'), 3);
	
	Cpang::String::iterator pos = s1.begin() + 2;
	pos = s1.insert(pos, s2.begin(), s2.end());
	pos = s1.erase(pos + 10, pos + 15);
	//pos = s1.insert(pos, s2.begin(), s2.end());
	//pos = s1.erase(pos + 1, pos + 10);
	//s1.erase(pos);
	Cpang::reverse(s1.begin(), s1.end());

	Cpang::String::iterator it;
	for (it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it;
	}
	cout << endl;

	for (auto& e : s1)
	{
		cout << e;
	}
	cout << endl;

	Cpang::String::reverse_iterator rit;
	for (rit = s1.rbegin(); rit != s1.rend(); rit++)
	{
		cout << *rit;
	}
	cout << endl;
	
	//string::const_iterator cit;
	//string::const_reverse_iterator crit;

	string s;
	int i;
	s.reserve(1000);
	s.resize(100);

	/*for (i = 1; i <= 106; i++)
	{
		s.push_back('a');
		cout << s.size() << ' ' << s.capacity() << endl;
	}*/
	
	cout << s.size() << ' ' << s.capacity() << endl;

	//s.find_first_of("0123456789");
	//s.find_first_not_of("0123456789");
	return 0;
}