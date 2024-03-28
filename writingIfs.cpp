#include <iostream>
#include <vector>
#include <string>

struct node {
	std::string title;
	int val;
};

int main() {
	int numOftitles, characters;
	scanf_s("%d %d", &numOftitles, &characters);
	std::vector<node> titles(numOftitles);
	for (int i = 0; i < numOftitles; ++i) {
		std::cin >> titles[i].title >> titles[i].val;
	}
	int power;
	for (int i = 0; i < characters; ++i) {
		scanf_s("%d", &power);
		int low = 0;
		int high = numOftitles - 1;
		int mid = 0;
		while (low <= high) {
			mid = (low + high) >> 1;
			if (!mid) {
				if (titles[mid].val >= power) {
					std::cout << titles[mid].title << '\n';
					break;
				}
				else low = mid + 1;
			}
			else {
				if (titles[mid].val < power) low = mid + 1;
				else if (titles[mid].val >= power && power > titles[mid-1].val) {
					std::cout << titles[mid].title << '\n';
					break;
				}
				else high = mid - 1;
			}
		}
	}
}