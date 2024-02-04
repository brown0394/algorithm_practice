#include <iostream>
#include <vector>
#include <algorithm>

struct node {
	int from;
	int to;
	int cost;
	bool operator < (const node& other) {
		return this->cost < other.cost;
	}
};

std::vector<std::vector<int>> connections;
std::vector<int> computers;
std::vector<node> costs;

void connectGroupless(int from, int to) {
	if (!computers[to]) {
		computers[to] = to;
		connections[to].push_back(from);
		connections[to].push_back(to);
	}
	else {
		connections[computers[to]].push_back(from);
	}
	computers[from] = computers[to];
}

bool connectGroup(int from, int to) {
	if (computers[from] == computers[to]) return false;
	int smallerGroup, biggerGroup;
	if (connections[computers[from]].size() <= connections[computers[to]].size()) {
		smallerGroup = computers[from];
		biggerGroup = computers[to];
	}
	else {
		smallerGroup = computers[to];
		biggerGroup = computers[from];
	}
	for (auto it = connections[smallerGroup].begin(); it != connections[smallerGroup].end(); ++it) {
		computers[*it] = biggerGroup;
		connections[biggerGroup].push_back(*it);
	}
	connections[smallerGroup].clear();
	return true;
}

int main() {
	int computer, lines;
	scanf_s("%d %d", &computer, &lines);
	connections.resize(computer + 1);
	computers.resize(computer + 1);
	int from, to, cost;
	for (int i = 0; i < lines; ++i) {
		scanf_s("%d %d %d", &from, &to, &cost);
		if (from != to) {
			costs.push_back({ from, to, cost });
		}
	}
	std::sort(costs.begin(), costs.end());
	int sum = 0;
	int count = 1;
	for (auto it = costs.begin(); it != costs.end(); ++it) {
		if (!computers[it->from]) {
			connectGroupless(it->from, it->to);
			sum += it->cost;
			++count;
		}
		else if (!computers[it->to]) {
			connectGroupless(it->to, it->from);
			sum += it->cost;
			++count;
		}
		else if (connectGroup(it->from, it->to)) {
			sum += it->cost;
			++count;
		}

		if (count == computer) break;
	}
	printf("%d\n", sum);
}
