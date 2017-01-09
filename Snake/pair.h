#pragma once
class pair
{
private:
	double a, b;

public:
	pair(const pair& s) : a(s.a), b(s.b) {}
	pair(pair& s) : a(s.a), b(s.b) {}
	pair(double x, double y) : a(x), b(y) {}

	inline const double const getA() const
	{
		return a;
	}

	inline const double const getB() const
	{
		return b;
	}

	pair& operator+=(const pair& right);

	pair& operator-=(const pair& right);

	bool operator==(const pair& right);

	const pair operator+(const pair& right);

	const pair operator-(const pair& right);
};
