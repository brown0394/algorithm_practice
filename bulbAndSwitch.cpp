#include <iostream>
#include <bitset>

void toggleBulbs(std::bitset<100'000>& cur, std::bitset<100'000>& target, int len, int* count) {
	for (int i = len; i > 1; --i) {
		if (cur[i] != target[i]) {
			cur[i].flip();
			cur[i - 1].flip();
			cur[i - 2].flip();
			++*count;
		}
	}
	if (cur[1] != target[1]) {
		cur[1].flip();
		cur[0].flip();
		++*count;
	}
}

int main() {
	std::bitset<100'000> bulbs;
	std::bitset<100'000> target;
	int len;
	std::cin >> len >> bulbs >> target;
	std::bitset<100'000> bulbs1stFlipped = bulbs;
	--len;
	bulbs1stFlipped[len].flip();
	bulbs1stFlipped[len - 1].flip();
	int count = 1, min = ~(1 << 31);
	toggleBulbs(bulbs1stFlipped, target, len, &count);
	if (bulbs1stFlipped[0] == target[0]) min = count;
	count = 0;
	toggleBulbs(bulbs, target, len, &count);
	if (bulbs[0] == target[0] && min > count) min = count;
	if (min == ~(1 << 31)) printf("-1\n");
	else printf("%d\n", min);
}
