#include <iostream>
#include <vector>
#include <queue>

struct info {
	int tallerThan;
	std::vector<int> smallerThan;
};

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int students, compares;
	std::cin >> students >> compares;
	std::vector<info> heightInfos(students + 1);
	for (int i = 0, smaller, taller; i < compares; ++i) {
		std::cin >> smaller >> taller;
		++heightInfos[taller].tallerThan;
		heightInfos[smaller].smallerThan.push_back(taller);
	}
	std::queue<int> q;
	for (int i = 1; i <= students; ++i) {
		if (heightInfos[i].tallerThan == 0) {
			q.push(i);
			--heightInfos[i].tallerThan;
		}
	}

	int cur = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		std::cout << cur << ' ';
		for (auto it = heightInfos[cur].smallerThan.begin(), end = heightInfos[cur].smallerThan.end();
			it != end; ++it) {
			--heightInfos[*it].tallerThan;
			if (heightInfos[*it].tallerThan == 0) {
				q.push(*it);
				--heightInfos[*it].tallerThan;
			}
		}
	}
	std::cout << '\n';
}