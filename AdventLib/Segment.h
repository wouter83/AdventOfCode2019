#pragma once

#undef max
#undef min
class Segment {
public:
	Segment(const Point& a, const Point& b) {
		p1 = a;
		p2 = b;
		xMin = std::min(p1.x, p2.x);
		xMax = std::max(p1.x, p2.x);
		yMin = std::min(p1.y, p2.y);
		yMax = std::max(p1.y, p2.y);
	}

	Point p1;
	Point p2;
	int xMin;
	int xMax;
	int yMin;
	int yMax;
};