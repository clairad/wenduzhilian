#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<set<char>, set<string> > mscss;
	set<char> sc;
	string str;

	int i;
	for (i = 0; i < n; i++)
	{
		cin >> str;
		for (auto& e : str)
		{
			sc.insert(e);
		}
		mscss[sc].insert(str);
		sc.clear();
	}

	cin >> str;
	for (auto& e : str)
	{
		sc.insert(e);
	}
	auto& ss = mscss[sc];
	ss.erase(str);
	int k;
	cin >> k;

	auto it = ss.begin();
	for (i = 1; i < k && it != ss.end(); i++, it++);
	if (it == ss.end())
	{
		return 0;
	}
	cout << *it;



	/*for (auto& e : mscss)
	{
		cout << '[';
		for (auto& e1 : e.first)
		{
			cout << e1 << ' ';
		}
		cout << ']';

		cout << ":[";
		for (auto& e1 : e.second)
		{
			cout << e1 << ' ';
		}
		cout << ']' << endl;
	}*/
	return 0;
}
