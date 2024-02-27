#include <iostream>
#include <cmath>

struct point {
	double x;
	double y;
	double z;
	void operator = (const point& other) {
		x = other.x;
		y = other.y;
		z = other.z;
	}
};

double getDistance(point& one, point& two) {
	double x = two.x - one.x;
	double y = two.y - one.y;
	double z = two.z - one.z;
	return std::sqrt((x * x) + (y * y) + (z * z));
}

double getLength(point& one) {
	return std::sqrt((one.x * one.x) + (one.y * one.y) + (one.z * one.z));
}

int main() {
	point a, b, c;
	scanf_s("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z, &c.x, &c.y, &c.z);
	b.x -= a.x;
	b.y -= a.y;
	b.z -= a.z;
	c.x -= a.x;
	c.y -= a.y;
	c.z -= a.z;
	double dotProd = (c.x * b.x) + (c.y * b.y) + (c.z * b.z);
	double minDist;
	if (dotProd <= 0) minDist = getLength(c);
	else {
		double lenB = getLength(b);
		double proj = dotProd / ((b.x * b.x) + (b.y * b.y) + (b.z * b.z));
		point projected {b.x * proj, b.y * proj, b.z * proj};
		proj = getLength(projected);
		if (lenB < proj) minDist = getDistance(b, c);
		else minDist = getDistance(projected, c);
	}
	printf("%.10lf\n", minDist);
}
