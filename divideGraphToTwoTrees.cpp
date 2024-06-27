#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

struct node {
	int parent, edgeN;
	std::unordered_set<int> children;
};

void bfs(int idx, std::vector<node>& nodeInfos, std::vector<int>& treeNodes,
	std::vector<int>& treeEdges) {
	std::queue<int> q;
	q.push(idx);
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		treeNodes.push_back(idx);
		for (auto it = nodeInfos[idx].children.begin(), end = nodeInfos[idx].children.end(); it != end; ++it) {
			q.push(*it);
		}
		if (nodeInfos[idx].edgeN) treeEdges.push_back(nodeInfos[idx].edgeN);
	}
}

void adoptTree(std::vector<node>& nodeInfos, int newParent, int newChild, int newEdgeN) {

	while (nodeInfos[newChild].parent) {
		int oldParent = nodeInfos[newChild].parent;
		int oldEdgeN = nodeInfos[newChild].edgeN;
		nodeInfos[newChild].parent = newParent;
		nodeInfos[newChild].edgeN = newEdgeN;
		nodeInfos[newParent].children.insert(newChild);
		nodeInfos[oldParent].children.erase(newChild);
		newEdgeN = oldEdgeN;
		newParent = newChild;
		newChild = oldParent;
	}
	nodeInfos[newChild].parent = newParent;
	nodeInfos[newChild].edgeN = newEdgeN;
	nodeInfos[newParent].children.insert(newChild);
}

void print(std::vector<int>& v) {
	printf("\n");
	if (v.empty()) return;
	std::sort(v.begin(), v.end());
	auto it = v.begin();
	printf("%d", *it++);
	for (auto end = v.end(); it != end; ++it) printf(" %d", *it);
}

int main() {
	int nodes, edges;
	scanf_s("%d %d", &nodes, &edges);
	std::vector<int> tree1Nodes;
	std::vector<int> tree1Edges;
	std::vector<int> tree2Nodes;
	std::vector<int> tree2Edges;
	std::vector<node> nodeInfos(nodes + 1, {0, 0});
	std::vector<bool> taken(nodes + 1);
	int trees = 0;
	int nodesTaken = 0;
	int from, to;
	for (int i = 1; i <= edges; ++i) {
		scanf_s("%d %d", &from, &to);
		if (nodeInfos[from].parent && nodeInfos[to].parent) {
			int root1 = nodeInfos[from].parent, root2 = nodeInfos[to].parent;
			while (nodeInfos[root1].parent) root1 = nodeInfos[root1].parent;
			while (nodeInfos[root2].parent) root2 = nodeInfos[root2].parent;
			if (root1 == root2) continue;
			if (root1 < root2) {
				adoptTree(nodeInfos, from, to, i);
			}
			else {
				adoptTree(nodeInfos, to, from, i);
			}
			--trees;
			continue;
		}
		else if (!nodeInfos[from].parent && nodeInfos[to].parent) {
			std::swap(from, to);
		}
		else if (!nodeInfos[from].parent && !nodeInfos[to].parent) {
			if (from > to) {
				std::swap(from, to);
			}
			if (!taken[to] && !taken[from]) ++trees;
		}

		nodeInfos[to].parent = from;
		nodeInfos[from].children.insert(to);
		nodeInfos[to].edgeN = i;
		if (!taken[to]) {
			taken[to] = true;
			++nodesTaken;
		}
		if (!taken[from]) {
			taken[from] = true;
			++nodesTaken;
		}
	}
	trees += (nodes - nodesTaken);
	if (trees > 2) {
		printf("-1\n");
		return 0;
	}
	else if (trees == 1) {
		while (!nodeInfos[to].children.empty()) {
			to = *nodeInfos[to].children.begin();
		}
		nodeInfos[nodeInfos[to].parent].children.erase(to);
		nodeInfos[to].parent = 0;
		nodeInfos[to].edgeN = 0;
	}
	for (int idx = 1; idx <= nodes; ++idx) {
		if (!nodeInfos[idx].parent) {
			if (tree1Nodes.empty()) bfs(idx, nodeInfos, tree1Nodes, tree1Edges);
			else {
				bfs(idx, nodeInfos, tree2Nodes, tree2Edges);
				break;
			}
		}
	}
	if (tree1Nodes.size() == tree2Nodes.size()) {
		printf("-1\n");
		return 0;
	}
	printf("%d %d", tree1Nodes.size(), tree2Nodes.size());
	print(tree1Nodes);
	print(tree1Edges);
	print(tree2Nodes);
	print(tree2Edges);
	putchar('\n');
}