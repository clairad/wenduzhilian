#include "cstring.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
using Cpang::string;

Cpang::string::string() : size(0)
{
	val = (char*)malloc(sizeof(char));
}

Cpang::string::string(const char* str) : size(strlen(str))
{
	val = (char*)malloc(size * sizeof(char));
	int i;
	for (i = 0; i < size; i++)
	{
		val[i] = str[i];
	}
}

Cpang::string::string(string& o) : size(o.size)
{
	val = (char*)malloc(size * sizeof(char)); //Éî¿½±´
	int i;
	for (i = 0; i < size; i++)
	{
		val[i] = o.val[i];
	}
}

Cpang::string::string(char ch, int n) : size(n)
{
	val = (char*)malloc(size * sizeof(char)); //Éî¿½±´
	int i;
	for (i = 0; i < size; i++)
	{
		val[i] = ch;
	}
}
Cpang::string::string(string& o, int start, int end) : size(end - start)
{
	val = (char*)malloc(size * sizeof(char)); //Éî¿½±´
	int i;
	for (i = start; i < end; i++)
	{
		val[i - start] = o.val[i];
	}
}

Cpang::string::~string()
{
	free(val);
}

Cpang::string& Cpang::string::operator=(Cpang::string o)
{
	free(val);
	size = o.size;
	val = (char*)malloc(size * sizeof(char)); //Éî¿½±´
	int i;
	for (i = 0; i < size; i++)
	{
		val[i] = o.val[i];
	}

	return *this;
}

Cpang::string Cpang::string::operator+(const string& o) const
{
	string res;

	res.size = size + o.size;
	free(res.val);
	res.val = (char*)malloc(res.size * sizeof(char));
	int i;
	for (i = 0; i < size;i++)
	{
		res.val[i] = val[i];
	}
	int j;
	for (j = 0; j < o.size; i++, j++)
	{
		res.val[i] = o.val[j];
	}
	return res;
}

void Cpang::string::printString()
{
	int i;
	for (i = 0; i < size; i++)
	{
		putchar(val[i]);
	}
}
