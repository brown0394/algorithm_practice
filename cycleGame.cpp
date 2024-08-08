#include <iostream>
#include <vector>

std::vector<int> parent;

int getParent(int cur) {
	int p = parent[cur];
	int count = 0;
	while (p != cur) {
		cur = p;
		p = parent[cur];
	}
	return p;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int points, rounds;
	std::cin >> points >> rounds;
	parent.resize(points, -1);

	int i = 1;
	for (int from, to; i <= rounds; ++i) {
		std::cin >> from >> to;
		if (parent[from] < 0 && parent[to] < 0) {
			parent[from] = from;
			parent[to] = from;
		}
		else if (parent[from] < 0 && parent[to] >= 0) {
			parent[from] = to;
		}
		else if (parent[from] >= 0 && parent[to] < 0) {
			parent[to] = from;
		}
		else {
			int p1 = getParent(from);
			int p2 = getParent(to);
			if (p1 == p2) break;
			parent[p2] = from;
		}
	}
	if (i <= rounds) std::cout << i << std::endl;
	else std::cout << 0 << std::endl;
}