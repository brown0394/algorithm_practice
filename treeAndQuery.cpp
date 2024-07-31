#include <iostream>
#include <vector>

std::vector<int> nodeCount;
std::vector<std::vector<int>> connection;
int countNodes(int cur, int parent){
	if (connection[cur].size() == 1 && parent) {
		nodeCount[cur] = 1;
		return 1;
	}
	int count = 1;
	for (auto it = connection[cur].begin(), end = connection[cur].end(); it != end; ++it) {
		if (*it == parent) continue;
		count += countNodes(*it, cur);
	}
	nodeCount[cur] = count;
	return count;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int vertexes, root, queries;
	std::cin >> vertexes >> root >> queries;
	nodeCount.resize(vertexes + 1);
	connection.resize(vertexes + 1);
	for (int i = 0, end = vertexes - 1; i < end; ++i) {
		int from, to;
		std::cin >> from >> to;
		connection[from].push_back(to);
		connection[to].push_back(from);
	}
	countNodes(root, 0);
	for (int i = 0; i < queries; ++i) {
		int subRoot;
		std::cin >> subRoot;
		std::cout << nodeCount[subRoot] << '\n';
	}
}