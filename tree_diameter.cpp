#include <iostream>
#include <vector>

struct node {
	int to;
	int cost;
};

class StretchingTree {
private:
	std::vector<std::vector<node>> tree;
	int max;
	int bfs(int idx, int cost);
public:
	StretchingTree(int p_vertexes);
	void printMaxLength();
};

StretchingTree::StretchingTree(int p_vertexes) : tree(p_vertexes + 1), max(0) {
	int from, to, cost;
	--p_vertexes;
	for (int i = 0; i < p_vertexes; ++i) {
		scanf_s("%d %d %d", &from, &to, &cost);
		tree[from].push_back(node{ to, cost });
	}
}

int StretchingTree::bfs(int idx, int cost) {
	int maxVal = 0;
	int secondMax = 0;
	int val = 0;
	for (int i = 0; i < tree[idx].size(); ++i) {
		val = bfs(tree[idx][i].to, tree[idx][i].cost);
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
	bfs(1, 0);
	printf("%d\n", max);
}

int main() {
	int vertexes;
	scanf_s("%d", &vertexes);
	StretchingTree tree(vertexes);
	tree.printMaxLength();
}