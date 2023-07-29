#include <iostream>
using namespace std;
#include "poker.h"


int main()
{
	AllPokers ap;
	ap.makeCards();
	Player p[3] = {0};
	
	int i;
	for (i = 0; i < 17; i++)
	{
		p[0].catchCard(ap.getCard());
		p[1].catchCard(ap.getCard());
		p[2].catchCard(ap.getCard());
	}
	p[0].catchCard(ap.getCard());
	p[0].catchCard(ap.getCard());
	p[0].catchCard(ap.getCard());

	p[0].printCards();
	cout << endl;
	p[1].printCards();
	cout << endl;
	p[2].printCards();
	return 0;
}