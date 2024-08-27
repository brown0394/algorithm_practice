#include <iostream>
#include <vector>

struct coord {
	long long x, y;
	coord operator - (const coord& other) {
		return { x - other.x, y - other.y };
	}
};

int ccw(coord one, coord two, coord three) {
	long long val = (one.x * two.y) - (one.y * two.x);
	if (val > 0) val = 1;
	else if (val < 0) val = -1;
	long long val2 = (one.x * three.y) - (one.y * three.x);
	if (val2 > 0) val2 = 1;
	else if (val2 < 0) val2 = -1;
	return val * val2;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	coord oneS, oneE, twoS, twoE;
	std::cin >> oneS.x >> oneS.y >> oneE.x >> oneE.y
		>> twoS.x >> twoS.y >> twoE.x >> twoE.y;
	int result1 = ccw(oneE - oneS, twoS - oneS, twoE - oneS);
	int result2 = ccw(twoE - twoS, oneS - twoS, oneE - twoS);
	int isPossible = 1;
	if (result1 == 1 || result2 == 1) isPossible = 0;
	else if (!result1 && !result2) {
		if (oneS.x > oneE.x) std::swap(oneS, oneE);
		if ((oneS.x > twoE.x && oneS.x > twoS.x) ||
			(oneE.x < twoE.x && oneE.x < twoS.x)) isPossible = 0;
		if (oneS.y > oneE.y) std::swap(oneS, oneE);
		if ((oneS.y > twoE.y && oneS.y > twoS.y) ||
			(oneE.y < twoE.y && oneE.y < twoS.y)) isPossible = 0;
	}
	std::cout << isPossible << '\n';
}