#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string getKey(const string& path, const string& num)
{
	int pos = path.rfind('\\');
	string res;
	pos++;
	if (path.size() - pos <= 16)
	{
		res = path.substr(pos);
	}
	else
	{
		res = path.substr(path.size() - 16);
	}
	res += " ";
	res += num;
	return res;
}

int main()
{
	string a, b;
	int n;

	cin >> n;
	vector<string> vs;
	unordered_map<string, int> data;
	string res;
	vs.reserve(100000);
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> a >> b;
		res = getKey(a, b);
		data[res]++;
		if (data[res] == 1)
		{
			vs.push_back(res);
		}
	}

	i = vs.size() - 8;
	if (i < 0)
	{
		i = 0;
	}
	for (; i < vs.size(); i++)
	{
		cout << vs[i] << ' ' << data[vs[i]] << endl;
	}

	return 0;
}

/*
11
D:\zwtymj\xccb\ljj\cqzlyaszjvlsjmkwoqijggmybr 645
E:\je\rzuwnjvnuz 633
C:\km\tgjwpb\gy\atl 637
F:\weioj\hadd\connsh\rwyfvzsopsuiqjnr 647
E:\ns\mfwj\wqkoki\eez 648
D:\cfmwafhhgeyawnool 649
E:\czt\opwip\osnll\c 637
G:\nt\f 633
F:\fop\ywzqaop 631
F:\yay\jc\ywzqaop 631
D:\zwtymj\xccb\ljj\cqzlyaszjvlsjmkwoqijggmybr 645

*/