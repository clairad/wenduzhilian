#include <iostream>
using namespace std;

class BirdBase {
public:
	virtual void name() = 0;

	void voice()
	{
		cout << "jiujiu" << endl;
	}
};

class hen : public BirdBase
{
public:
	void name()
	{
		cout << "hen" << endl;
	}

	void voice()
	{
		cout << "gegeda" << endl;
		cout << "gegeda" << endl;
	}
};

class duck : public BirdBase
{
public:
	void name()
	{
		cout << "duck" << endl;
	}

	void voice()
	{
		cout << "gagaga" << endl;
	}
};

int main()
{
	hen kun;
	kun.name();
	kun.voice();
	duck d;
	d.name();
	d.voice();

	return 0;
}