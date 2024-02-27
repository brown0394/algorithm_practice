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

int main() {
	point a, b, c, mid, mid2;
	scanf_s("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z, &c.x, &c.y, &c.z);
	double distM, distM2, minDist = 0;
	for (int i = 0; i < 10000; ++i) {
		mid.x = ((a.x * 2) + b.x) / 3;
		mid.y = ((a.y * 2) + b.y) / 3;
		mid.z = ((a.z * 2) + b.z) / 3;
		mid2.x = ((b.x * 2) + a.x) / 3;
		mid2.y = ((b.y * 2) + a.y) / 3;
		mid2.z = ((b.z * 2) + a.z) / 3;
		distM = getDistance(mid, c);
		distM2 = getDistance(mid2, c);
		if (distM <= distM2) {
			minDist = distM;
			b = mid2;
		}
		else {
			minDist = distM2;
			a = mid;
		}
	}
	printf("%.10lf\n", minDist);
}
