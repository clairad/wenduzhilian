#include <iostream>
using namespace std;

class fraction
{
	long long m_numerator; //·Ö×Ó
	long long m_denominator;//·ÖÄ¸
	void simplify();
public:

	fraction(long long numerator, long long denominator);
	fraction operator+(fraction const& o) const;
	fraction operator*(fraction const& o) const;
	friend std::ostream& operator<<(std::ostream& os, fraction const& o);

};

fraction::fraction(long long numerator, long long denominator)
{
	m_numerator = numerator;
	m_denominator = denominator;
}

fraction fraction::operator+(fraction const& o) const
{
	long long newNumerator = m_numerator * o.m_denominator + o.m_numerator * m_denominator;
	long long newDenominator = m_denominator * o.m_denominator;
	return fraction(newNumerator, newDenominator);
}

fraction fraction::operator*(fraction const& o) const
{
	long long newNumerator = m_numerator * o.m_numerator;
	long long newDenominator = m_denominator * o.m_denominator;
	return fraction(newNumerator, newDenominator);
}

void fraction::simplify()
{
	long long gcd = 1;
	long long smaller = (m_numerator < m_denominator) ? m_numerator : m_denominator;

	for (long long i = 1; i <= smaller; i++)
	{
		if (m_numerator % i == 0 && m_denominator % i == 0)
			gcd = i;
	}

	m_numerator /= gcd;
	m_denominator /= gcd;

}

std::ostream& operator<<(std::ostream& os, fraction const& o)
{
	os << o.m_numerator << "/" << o.m_denominator;
	return os;
}

int main()
{
	fraction f1(1, 2);
	fraction f3 = fraction(4, 7) * fraction(4, 9);
	cout << f3 << endl;

	return 0;
}

