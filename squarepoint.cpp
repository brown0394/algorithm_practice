#include <iostream>

int main() {
	int x1, x2, x3, y1, y2, y3;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	bool x = false, y = false;
	int diffx, diffy;
	if (x1 == x2) {
		x = true;
		diffx = x3;
	}
	else if (x1 == x3) {
		x = true;
		diffx = x2;
	}
	if (y1 == y2) {
		y = true;
		diffy = y3;
	}
	else if (y1 == y3) {
		y = true;
		diffy = y2;
	}

	if (x && y) {
		std::cout << diffx << ' ' << diffy << std::endl;
	}
	else if (!x) {
		std::cout << x1 << ' ' << diffy << std::endl;
	}
	else if (!y) {
		std::cout << diffx << ' ' << y1 << std::endl;
	}
}