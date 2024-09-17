#include <iostream>
#include <vector>
#include <queue>

struct info {
	int in;
	std::vector<int> priorTo;
};

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int problems, connections;
	std::cin >> problems >> connections;
	std::vector<info> problemInfos(problems + 1);
	for (int i = 0, A, B; i < connections; ++i) {
		std::cin >> A >> B;
		problemInfos[A].priorTo.push_back(B);
		++problemInfos[B].in;
	}
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int i = 1; i <= problems; ++i) {
		if (problemInfos[i].in == 0) pq.push(i);
	}
	int idx;
	while (!pq.empty()) {
		idx = pq.top();
		pq.pop();
		std::cout << idx << ' ';
		for (int& next : problemInfos[idx].priorTo) {
			if (--problemInfos[next].in == 0) {
				pq.push(next);
			}
		}

	}
	std::cout << '\n';
}