#include <iostream>
#include <vector>
#include <deque>
#include <bitset>

int main() {
	int meals;
	scanf_s("%d", &meals);
	std::vector<int> costs(meals + 1);
	std::vector<int> menuidxes(meals + 1);
	for (int i = 1; i <= meals; ++i) {
		scanf_s("%d", &costs[i]);
	}
	int menuCost;
	scanf_s("%d", &menuCost);
	std::bitset<260> menu;
	for (int i = 0; i < 4; ++i) {
		int idx;
		scanf_s("%d", &idx);
		menu[idx] = true;
	}
	int foodsPicked;
	scanf_s("%d", &foodsPicked);
	int totalCost = 0;
	std::deque<int> menus;
	for (int i = 0; i < foodsPicked; ++i) {
		int idx;
		scanf_s("%d", &idx);
		if (menu[idx]) {
			if (menus.size() <= menuidxes[idx]) menus.push_back(costs[idx]);
			else menus[menuidxes[idx]] += costs[idx];
			++menuidxes[idx];
		}
		totalCost += costs[idx];
	}
	int menuCheaper = 0;
	for (auto it = menus.begin(), end = menus.end(); it != end; ++it) {
		if (*it > menuCost) {
			totalCost -= *it;
			++menuCheaper;
		}
	}
	printf("%d\n", totalCost + (menuCheaper * menuCost));
}