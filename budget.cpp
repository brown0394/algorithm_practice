#include <iostream>
#include <vector>

std::vector<int> budgets;
int budget;
int cities;
bool checkBudget(int perCityBudget) {
	int sum = 0;
	for (int i = 0; i < cities; ++i) {
		if (budgets[i] < perCityBudget) sum += budgets[i];
		else sum += perCityBudget;
	}
	return sum <= budget;
}

int main() {
	scanf_s("%d", &cities);
	budgets.resize(cities);
	int max = 0;
	for (int i = 0; i < cities; ++i) {
		scanf_s("%d", &budgets[i]);
		if (budgets[i] > max) max = budgets[i];
	}
	scanf_s("%d", &budget);
	int low = 0, high = max;
	int mid;
	while (low < high) {
		mid = (low + high + 1) >> 1;
		if (checkBudget(mid)) {
			low = mid;
		}
		else {
			high = mid - 1;
		}
	}
	printf("%d\n", low);
}
