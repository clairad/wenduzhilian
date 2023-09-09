#pragma once
#include <iostream>
using std::cout;
using std::endl;

class fraction {
	long long m_numerator;	//·Ö×Ó
	long long m_denominator;//·ÖÄ¸ 

	static long long gcd(long long a, long long b)
	{
		long long c = a % b;
		while (c)
		{
			a = b;
			b = c;
			c = a % b;
		}
		return b;
	}
public:
	fraction(long long numerator, long long denominator) 
		: m_numerator(numerator)
		, m_denominator(denominator)
	{}

	fraction operator+(fraction const& o) const
	{
		long long min = m_denominator * o.m_denominator / gcd(m_denominator, o.m_denominator);
		long long tmpn = m_numerator * min / m_denominator +
						o.m_numerator * min / o.m_denominator;
		if (tmpn)
		{
			long long g = gcd(min, tmpn);
			min /= g;
			tmpn /= g;
		}
		return fraction(tmpn, min);
	}

	fraction operator*(fraction const& o) const
	{
		long long tmpn = m_numerator * o.m_numerator;
		long long tmpd = m_denominator * o.m_denominator;
		if (tmpn)
		{
			long long g = gcd(tmpd, tmpn);
			tmpd /= g;
			tmpn /= g;
		}
		return fraction(tmpn, tmpd);
	}

	friend std::ostream& operator<<(std::ostream& os, fraction const& o);
};

std::ostream& operator<<(std::ostream& os, fraction const& o)
{
	if (o.m_denominator == 0)
	{
		os << "INF" << endl;
		return os;
	}
	if (o.m_numerator == 0)
	{
		os << 0 << endl;
		return os;
	}
	
	long long tmpnum = 0;
	long long tmptor = o.m_numerator;
	if (o.m_numerator > o.m_denominator)
	{
		tmpnum = o.m_numerator / o.m_denominator;
		tmptor = o.m_numerator % o.m_denominator;
	}
	if (tmpnum)
	{
		os << tmpnum << ' ';
	}
	if (tmptor)
	{
		os << tmptor << '/' << o.m_denominator;
	}
	
	return os;
}