#include <iostream>
#include <queue>
using namespace std;
class eatApple {
public:
    int brokenDay;
    static int dayNum;
    int appleNum;

    eatApple(int app, int day, int dayn) : appleNum(app)
    {
        brokenDay = day + dayn;
    }
};
int eatApple::dayNum = 0;

class AppCmp {
public:
    bool operator()(const eatApple& a, const eatApple& b)
    {
        return a.brokenDay - a.dayNum > b.brokenDay - b.dayNum;
    }
};

class Solution {

public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<eatApple, vector<eatApple>, AppCmp> pea;
        eatApple tmp(0, 0, 0);
        int i, count = 0;
        for (i = 0; i < apples.size() || !pea.empty(); i++)
        {
            eatApple::dayNum = i;
            if (i < apples.size() && apples[i])
            {
                pea.push(eatApple(apples[i], days[i], i));
            }

            while (!pea.empty() && pea.top().brokenDay <= i)
            {
                pea.pop();
            }

            if (!pea.empty() && pea.top().appleNum > 0)
            {
                tmp = pea.top();
                tmp.appleNum--;
                pea.pop();
                if(tmp.appleNum)
                { 
                    pea.push(tmp);
                }
                count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> a{ 1,2,3,5,2 };
    vector<int> b{ 3,2,1,4,2 };
    cout << s.eatenApples(a, b);

	return 0;
}