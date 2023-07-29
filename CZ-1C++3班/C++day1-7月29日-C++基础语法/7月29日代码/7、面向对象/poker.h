#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

class Poker
{
public:
	int point;

	int getColor()
	{
		if (point > 51)
		{
			return 4;
		}
		return point % 4;
	}

	int getPoint()
	{
		int retnum[] = { 3,4,5,6,7,8,9,10,11,12,13,1,2,14 };
		if (point == 53)
		{
			return 15;
		}
		return retnum[point / 4];
	}

	void printCard()
	{
		const char* printColor[] = { "方片", "梅花", "红桃", "黑桃"};
		char printPoint[] = "34567890JQKA2";

		if (point == 52)
		{
			cout << "小王";
		}
		else if(point == 53)
		{
			cout << "大王";
		}
		else
		{
			cout << printColor[point % 4];
			if (point / 4 == 7)
			{
				cout << '1';
			}
			cout << printPoint[point / 4];
		}
	}
};

class AllPokers
{
public:
	Poker allCards[54];
	int pos;

	void makeCards()
	{
		int arr[54];
		int i;
		for (i = 0; i < 54; i++)
		{
			arr[i] = i;
		}

		srand(time(NULL));
		rand();
		int tmp;
		for (i = 0; i < 54; i++)
		{
			tmp = rand() % 54;
			while (arr[tmp] == -1)
			{
				tmp++;
				tmp %= 54;
			}
			allCards[i].point = arr[tmp];
			arr[tmp] = -1;
		}
		pos = 0;
	}

	Poker getCard()
	{
		pos++;
		return allCards[pos - 1];
	}

	void printCards()
	{
		int i;
		for (i = 0; i < 54; i++)
		{
			allCards[i].printCard();
			cout << ' ';
		}
	}
};

bool operator>(Poker a, Poker b)
{
	return a.point > b.point;
}

void swap(Poker& a, Poker& b)
{
	Poker tmp;
	tmp = a;
	a = b;
	b = tmp;
}

class Player {
public:
	bool job;
	Poker allCards[20];
	int pos;

	void init()
	{
		pos = 0;
	}

	void bubbleSort()
	{
		int i, j;
		int n = pos;
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - 1 - i; j++)
			{
				if (allCards[j] > allCards[j + 1])
				{
					swap(allCards[j], allCards[j + 1]);
				}
			}
		}
	}

	void printCards()
	{
		int i;
		bubbleSort();
		for (i = 0; i < pos; i++)
		{
			allCards[i].printCard();
			cout << ' ';
		}
	}

	void catchCard(Poker p)
	{
		allCards[pos] = p;
		pos++;
	}
};