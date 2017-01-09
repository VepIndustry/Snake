#include "pair.h"
#include <cmath>

pair & pair::operator+=(const pair & right)
{
	a += right.a;
	b += right.b;
	return *this;
}

pair & pair::operator-=(const pair & right)
{
	a -= right.a;
	b -= right.b;
	return *this;
}

bool pair::operator==(const pair & right)
{
	return (a == right.a && b == right.b) ? true : false;
}

const pair pair::operator+(const pair & right)
{
	return pair(a + right.a, b + right.b);
}

const pair pair::operator-(const pair & right)
{
	return pair(a - right.a, b - right.b);
}