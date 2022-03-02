#include <iostream>

int main() {
	int x, y, w, h;
	std::cin >> x >> y >> w >> h;

	int xy;
	if (x >= y) {
		xy = y;
	}
	else {
		xy = x;
	}
	int wh;
	if (w - x >= h - y) {
		wh = h - y;
	}
	else {
		wh = w - x;
	}
	if (xy <= wh) {
		std::cout << xy << std::endl;
	}
	else {
		std::cout << wh << std::endl;
	}

}