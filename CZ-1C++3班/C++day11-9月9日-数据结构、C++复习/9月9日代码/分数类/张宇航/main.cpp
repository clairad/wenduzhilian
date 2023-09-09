#include <iostream>
using namespace std;

class fraction {
	long long m_numerator; //·Ö×Ó
	long long m_denominator;//·ÖÄ¸
public:
	fraction(long long numerator, long long denominator)
	{
		m_numerator = numerator;
		m_denominator = denominator;
	}

	long long zzxc(long long a, long long b)
	{
		long long tmp;
		tmp = a % b;
		while (tmp)
		{
			a = b;
			b = tmp;
			tmp = a % b;
		}
		return b;
	}

	fraction operator+(fraction const& o)
	{
		long long tmp1 = zzxc(m_denominator, o.m_denominator);
		long long tmp2 = m_denominator * o.m_denominator / tmp1;
		m_denominator = tmp2;
		m_numerator = m_numerator * (tmp2 / m_denominator) + o.m_numerator * (tmp2 / o.m_denominator);
		return *this;

	}
	fraction operator*(fraction const& o)
	{
		long long tmp1 = zzxc(m_denominator, o.m_numerator);
		long long tmp2 = zzxc(m_numerator, o.m_denominator);
		m_denominator = m_denominator / tmp1 * o.m_denominator / tmp2;
		m_numerator = m_numerator / tmp2 * o.m_numerator / tmp1;
		long long tmp3 = zzxc(m_numerator, m_denominator);
		m_denominator = m_denominator / tmp3;
		m_numerator = m_numerator / tmp3;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, fraction const& o);
};

ostream& operator<<(std::ostream& os, fraction const& o)
{
	cout << o.m_numerator << " / " << o.m_denominator;
	return os;
}

int main()
{
	fraction f1(4, 8);
	fraction f2(1, 9);
	cout << f1 + f2;
	return 0;
}