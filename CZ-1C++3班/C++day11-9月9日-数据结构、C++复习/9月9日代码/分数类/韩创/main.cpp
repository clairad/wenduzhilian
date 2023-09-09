#include <iostream>
using namespace std;

class fraction {
	long long m_numerator; //分子
	long long m_denominator;//分母
public:

	long long fun1(long a, long b) const// 寻找a,b的最大公因数
	{
		int c = a < b ? a : b;
		int tmp = 1;
		int i;
		for (i = 2; i <= c; i++)
		{
			if (a % i == 0 && b % i == 0)
			{
				tmp = i;
			}
		}
		return tmp;
	}

	fraction(long long numerator, long long denominator)
	{
		int tmp = fun1(numerator, denominator);
		m_numerator = numerator / tmp;
		m_denominator = denominator / tmp;
	}

	fraction operator+(fraction const& o) const
	{
		long long num, den;
		num = m_numerator * o.m_denominator + m_denominator * o.m_numerator;
		den = m_denominator * o.m_denominator;
		long long tmp = fun1(num, den);
		fraction a(num / tmp, den / tmp);
		return a;
	}

	fraction operator*(fraction const& o) const
	{
		long long num, den;
		num = m_numerator * o.m_numerator;
		den = m_denominator * o.m_denominator;
		long long tmp = fun1(num, den);
		fraction a(num / tmp, den / tmp);
		return a;
	}

	friend std::ostream& operator<<(std::ostream& os, fraction const& o)
	{
		if (o.m_numerator > o.m_denominator)
		{
			os << o.m_numerator / o.m_denominator << ' ' << o.m_numerator % o.m_denominator << '/' << o.m_denominator << endl;
			return os;
		}
		os << o.m_numerator << '/' << o.m_denominator << endl;
		return os;
	}
};

int main()
{
	fraction a(4, 3);
	fraction b(7, 6);
	cout << (a + b);

	return 0;
}