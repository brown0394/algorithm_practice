#include <iostream>
#include <algorithm>

int main() {
	int side[3];
	while (true) {
		scanf_s("%d %d %d", &side[0], &side[1], &side[2]);
		if (!side[0] && !side[1] && !side[2]) break;
		if (side[0] == side[1]) {
			if (side[0] == side[2]) {
				printf("Equilateral\n");
			}
			else if (side[0] + side[1] > side[2]) printf("Isosceles\n");
			else printf("Invalid\n");
		}
		else if (side[0] == side[2]) {
			if (side[0] + side[2] > side[1]) printf("Isosceles\n");
			else printf("Invalid\n");
		}
		else {
			if (side[1] == side[2]) {
				if (side[1] + side[2] > side[0]) printf("Isosceles\n");
				else printf("Invalid\n");
			}
			else {
				std::sort(side, side + 3);
				if (side[0] + side[1] > side[2]) printf("Scalene\n");
				else printf("Invalid\n");
			}
		}
	}
	
	
}
