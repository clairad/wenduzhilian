#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>

class HighAcc
{
	std::vector<char> m_num;
	bool m_minusFlag;

	int hacmp(const HighAcc& hao) const
	{
		int flag = 1;
		if (m_minusFlag == false && hao.m_minusFlag == true)
		{
			return 1;
		}
		else if (m_minusFlag == true && hao.m_minusFlag == false)
		{
			return -1;
		}
		else if (m_minusFlag == true && hao.m_minusFlag == true)
		{
			flag = -1;
		}

		if(m_num.size() > hao.m_num.size())
		{
			return 1 * flag;
		}
		else if (m_num.size() < hao.m_num.size())
		{
			return -1 * flag;
		}
		else
		{
			int i;
			for (i = m_num.size() - 1; i >= 0; i--)
			{
				if (m_num[i] > hao.m_num[i])
				{
					return 1 * flag;
				}
				else if (m_num[i] < hao.m_num[i])
				{
					return -1 * flag;
				}
			}
			return 0;
		}
	}

	HighAcc add(const HighAcc& ha) const
	{
		HighAcc add1 = *this, add2 = ha;
		if (add1.m_num.size() < add2.m_num.size())
		{
			add1.m_num.resize(ha.m_num.size(), 0);
		}
		else
		{
			add2.m_num.resize(m_num.size(), 0);
		}

		HighAcc res;
		res.m_num.resize(add1.m_num.size() + 1, 0);

		int i, tmp;
		for (i = 0; i < add1.m_num.size(); i++)
		{
			tmp = add1.m_num[i] + add2.m_num[i] + res.m_num[i];
			res.m_num[i] = tmp % 10;
			res.m_num[i + 1] = tmp / 10;
		}

		if (res.m_num.back() == 0)
		{
			res.m_num.pop_back();
		}
		return res;
	}

	HighAcc mul(const HighAcc& ha) const
	{
		const HighAcc &mul1 = *this;
		const HighAcc &mul2 = ha;
		HighAcc res;
		if (mul1 == res || mul2 == res)
		{
			return res;
		}
		res.m_num.resize(mul1.m_num.size() + mul2.m_num.size(), 0);
		int i, j, tmp;
		for (i = 0; i < mul1.m_num.size(); i++)
		{
			for (j = 0; j < mul2.m_num.size(); j++)
			{
				tmp = mul1.m_num[i] * mul2.m_num[j] + res.m_num[i + j];
				res.m_num[i + j] = tmp % 10;
				res.m_num[i + j + 1] += tmp / 10;
			}
		}

		if (res.m_num.back() == 0)
		{
			res.m_num.pop_back();
		}
		return res;
	}

	HighAcc sub(const HighAcc& ha) const
	{
		HighAcc sub1 = *this;
		HighAcc sub2 = ha;
		HighAcc res;
		if (*this < ha)
		{
			res.m_minusFlag = true;
			sub1.m_num.swap(sub2.m_num);
			std::swap(sub1.m_minusFlag, sub2.m_minusFlag);
		}
		res.m_num.resize(sub1.m_num.size() + 1, 0);
		int i, tmp;
		for (i = 0; i < sub1.m_num.size(); i++)
		{
			tmp = sub1.m_num[i] + 10 - sub2.m_num[i] + res.m_num[i];
			res.m_num[i] = tmp % 10;
			res.m_num[i + 1] = tmp / 10 - 1;
		}

		while (res.m_num.size() > 1 && res.m_num.back() == 0)
		{
			res.m_num.pop_back();
		}
		return res;
	}

	static int divcmp(const HighAcc& haoa, size_t size, const HighAcc& haob)
	{
		if (size > haob.m_num.size())
		{
			return 1;
		}
		else if (size < haob.m_num.size())
		{
			return -1;
		}
		else
		{
			int i;
			for (i = size - 1; i >= 0; i--)
			{
				if (haoa.m_num[i + haoa.m_num.size() - size] > haob.m_num[i])
				{
					return 1;
				}
				else if (haoa.m_num[i + haoa.m_num.size() - size] < haob.m_num[i])
				{
					return -1;
				}
			}
			return 0;
		}
	}

	static void divsub(HighAcc& haoa, size_t size, const HighAcc& haob)
	{
		int gap = haoa.m_num.size() - size;
		HighAcc res;
		HighAcc div2 = haob;
		div2.m_num.resize(size);
		res.m_num.resize(haoa.m_num.size() + 1);
		int i, tmp;
		for (i = 0; i < size; i++)
		{
			tmp = haoa.m_num[i + gap] + 10 - div2.m_num[i] + res.m_num[i];
			res.m_num[i] = tmp % 10;
			res.m_num[i + 1] = tmp / 10 - 1;
		}
		while (res.m_num.size() > 1 && res.m_num.back() == 0)
		{
			res.m_num.pop_back();
		}
		std::copy(res.m_num.begin(), res.m_num.end(), haoa.m_num.begin() + gap);
		haoa.m_num.resize(gap + res.m_num.size());
	}

	HighAcc div(const HighAcc& ha) const
	{
		HighAcc res;
		res.m_num.resize(m_num.size());
		HighAcc tmp = *this;
		
		int i;
		int flag = 0;
		int count = 0;
		for (i = m_num.size() - 1; i >= 0; i--)
		{
			while (divcmp(tmp, tmp.m_num.size() - i, ha) >= 0)
			{
				if (flag == 0)
				{
					res.m_num.resize(i + 1);
					flag = 1;
				}
				divsub(tmp, tmp.m_num.size() - i, ha);
				count++;
			}
			res.m_num[i] = count;
			count = 0;
		}
		if (flag == 0)
		{
			res.m_num.resize(1);
		}
		return res;
	}

	HighAcc mod(const HighAcc& ha) const
	{
		HighAcc res;
		res.m_num.resize(m_num.size());
		HighAcc tmp = *this;

		int i;
		int flag = 0;
		int count = 0;
		for (i = m_num.size() - 1; i >= 0; i--)
		{
			while (divcmp(tmp, tmp.m_num.size() - i, ha) >= 0)
			{
				if (flag == 0)
				{
					res.m_num.resize(i + 1);
					flag = 1;
				}
				divsub(tmp, tmp.m_num.size() - i, ha);
				count++;
			}
			res.m_num[i] = count;
			count = 0;
		}
		return tmp;
	}
public:
	HighAcc() : m_minusFlag(false)
	{
		m_num.push_back(0);
	}

	HighAcc(const char str[]) : m_minusFlag(false)
	{
		if (*str == '-')
		{
			m_minusFlag = true;
			str++;
		}

		while (*str == '0')
		{
			str++;
		}

		m_num.reserve(100);
		m_num.resize(strlen(str));
		int i;
		for (i = 0; i < m_num.size(); i++)
		{
			m_num[i] = str[m_num.size() - i - 1] - '0';
		}
		if (m_num.size() == 0)
		{
			m_num.resize(1, 0);
		}
	}

	HighAcc(long long ll) : m_minusFlag(false)
	{
		if (ll < 0)
		{
			ll *= -1;
			m_minusFlag = true;
		}

		long long i;
		for (i = ll; i; i /= 10)
		{
			m_num.push_back(i % 10);
		}
	}

	HighAcc(const HighAcc& hao) : m_minusFlag(hao.m_minusFlag)
	{
		m_num = hao.m_num;
	}

	bool operator>(const HighAcc& hao) const { return hacmp(hao) > 0; }
	bool operator<(const HighAcc& hao) const { return hacmp(hao) < 0; }
	bool operator>=(const HighAcc& hao) const { return hacmp(hao) >= 0; }
	bool operator<=(const HighAcc& hao) const { return hacmp(hao) <= 0; }
	bool operator==(const HighAcc& hao) const { return hacmp(hao) == 0; }
	bool operator!=(const HighAcc& hao) const { return hacmp(hao) != 0; }

	HighAcc operator+(HighAcc& hao)
	{ 
		HighAcc res;
		if (m_minusFlag == true && hao.m_minusFlag == false)
		{
			m_minusFlag = false;
			res = sub(hao);
			res.m_minusFlag = !res.m_minusFlag;
			m_minusFlag = true;
		}
		else if (m_minusFlag == false && hao.m_minusFlag == true)
		{
			hao.m_minusFlag = false;
			res = sub(hao);
			hao.m_minusFlag = true;
		}
		else if (m_minusFlag == true && hao.m_minusFlag == true)
		{
			res = add(hao);
			res.m_minusFlag = true;
		}
		else
		{
			res = add(hao);
		}
		return res;
	}
	HighAcc operator-(const HighAcc & hao) const { return sub(hao); }
	HighAcc operator*(const HighAcc& hao) const { return mul(hao); }
	HighAcc operator/(const HighAcc& hao) const { return div(hao); }
	HighAcc operator%(const HighAcc& hao) const { return mod(hao); }

	HighAcc& operator+=(const HighAcc& hao)
	{ 
		*this = add(hao);
		return *this;
	}

	HighAcc& operator-=(const HighAcc& hao)
	{
		*this = sub(hao);
		return *this;
	}

	HighAcc& operator*=(const HighAcc& hao)
	{
		*this = mul(hao);
		return *this;
	}

	HighAcc& operator=(const HighAcc& hao)
	{
		m_num = hao.m_num;
		m_minusFlag = hao.m_minusFlag;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const HighAcc& hao);
};

std::ostream& operator<<(std::ostream& os, const HighAcc& hao)
{
	std::vector<char>::const_reverse_iterator vri;
	
	if (hao.m_minusFlag)
	{
		os << '-';
	}
	for (vri = hao.m_num.crbegin(); vri != hao.m_num.crend(); vri++)
	{
		os << (int)*vri;
	}

	return os;
}