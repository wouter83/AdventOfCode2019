#pragma once

class Point
{
public:
	Point();
	Point(int a, int b);

	int x;
	int y;

	bool operator==(const Point& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}
	bool operator!=(const Point& rhs) const
	{
		return !(*this == rhs);
	}
};