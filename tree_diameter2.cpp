#include <iostream>
#include <vector>
#include <map>

struct node {
	int to;
	int cost;
};

class StretchingTree {
private:
	std::vector<std::map<int, int>> tree;
	int max;
	int bfs(int idx, int cost, int parent);
public:
	StretchingTree(int p_vertexes);
	void printMaxLength();
};

StretchingTree::StretchingTree(int p_vertexes) : tree(p_vertexes + 1), max(0) {
	int from, to, cost;
	std::map<int, int>::iterator found;
	for (int i = 0; i < p_vertexes; ++i) {
		scanf_s("%d", &from);
		while (true) {
			scanf_s("%d", &to);
			if (to < 0) break;
			scanf_s("%d", &cost);
			found = tree[from].find(to);
			if (found == tree[from].end()) {
				tree[from].insert({ to, cost });
				tree[to].insert({ from, cost });
			}
			else if (found->second < cost) {
				found->second = cost;
				found = tree[to].find(from);
				found->second = cost;
			}
		}

	}
}

int StretchingTree::bfs(int idx, int cost, int parent) {
	int maxVal = 0;
	int secondMax = 0;
	int val = 0;
	for (auto it = tree[idx].begin(); it != tree[idx].end(); ++it) {
		if (it->first == parent) continue;
		val = bfs(it->first, it->second, idx);
		if (val > maxVal) {
			if (maxVal > secondMax) secondMax = maxVal;
			maxVal = val;
		}
		else if (val > secondMax) secondMax = val;
	}
	if (maxVal + secondMax > max) max = maxVal + secondMax;
	return cost + maxVal;
}

void StretchingTree::printMaxLength() {
	bfs(1, 0, 0);
	printf("%d\n", max);
}

int main() {
	int vertexes;
	scanf_s("%d", &vertexes);
	StretchingTree tree(vertexes);
	tree.printMaxLength();
}