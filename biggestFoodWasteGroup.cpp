#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

struct node {
	int row;
	int col;
};


int main() {
	int row, col, foodWaste;
	scanf_s("%d %d %d", &row, &col, &foodWaste);
	std::vector<std::bitset<102>> wastes(row + 2);
	std::vector<node> foodWastes(foodWaste);
	for (int i = 0; i < foodWaste; ++i) {
		scanf_s("%d %d", &foodWastes[i].row, &foodWastes[i].col);
		wastes[foodWastes[i].row][foodWastes[i].col] = true;
	}
	std::queue<node> q;
	int k, l, group;
	int maxWasteSize = 0;
	for (auto it = foodWastes.begin(); it != foodWastes.end(); ++it) {
		if (wastes[it->row][it->col]) {
			q.push({ it->row, it->col });
			wastes[it->row][it->col] = false;
			group = 0;
			while (!q.empty()) {
				k = q.front().row;
				l = q.front().col;
				++group;
				q.pop();
				if (wastes[k + 1][l]) {
					wastes[k + 1][l] = false;
					q.push({ k + 1, l });
				}
				if (wastes[k - 1][l]) {
					wastes[k - 1][l] = false;
					q.push({ k - 1, l });
				}
				if (wastes[k][l + 1]) {
					wastes[k][l + 1] = false;
					q.push({ k, l + 1 });
				}
				if (wastes[k][l - 1]) {
					wastes[k][l - 1] = false;
					q.push({ k, l - 1 });
				}
			}
			if (group > maxWasteSize) maxWasteSize = group;
		}
	}
	printf("%d\n", maxWasteSize);
}
