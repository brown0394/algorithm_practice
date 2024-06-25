#include <iostream>
#include <vector>
#include <queue>

struct node {
	int parent, lchild, rchild, edgeN;
};

void bfs(int idx, std::vector<node>& nodeInfos, std::vector<int>& treeNodes,
	std::vector<int>& treeEdges) {
	std::queue<int> q;
	q.push(idx);
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		treeNodes.push_back(idx);
		if (nodeInfos[idx].lchild) q.push(nodeInfos[idx].lchild);
		if (nodeInfos[idx].rchild) q.push(nodeInfos[idx].rchild);
		if (nodeInfos[idx].edgeN) treeEdges.push_back(nodeInfos[idx].edgeN);
	}
}

void print(std::vector<int>::iterator it, std::vector<int>::iterator end) {
	printf("\n%d", *it++);
	for (; it != end; ++it) printf(" %d", *it);
}

int main() {
	int nodes, edges;
	scanf_s("%d %d", &nodes, &edges);
	if (nodes <= 2 || edges < nodes - 2) {
		printf("-1\n");
		return 0;
	}
	std::vector<int> tree1Nodes;
	std::vector<int> tree1Edges;
	std::vector<int> tree2Nodes;
	std::vector<int> tree2Edges;
	std::vector<node> nodeInfos(nodes + 1, {0, 0});
	
	int trees = 0;
	int nodesTaken = 0;
	int from, to;
	for (int i = 1; i <= edges; ++i) {
		scanf_s("%d %d", &from, &to);
		if (!nodeInfos[from].parent && nodeInfos[to].parent) {
			std::swap(from, to);
		}
		else if (!nodeInfos[from].parent && !nodeInfos[to].parent) {
			if (from > to) {
				std::swap(from, to);
			}
			++trees;
			++nodesTaken;
		}
		else if (nodeInfos[from].parent && nodeInfos[to].parent) continue;
		nodeInfos[to].parent = from;
		if (!nodeInfos[from].lchild) {
			nodeInfos[from].lchild = to;
		}
		else if (!nodeInfos[from].rchild) {
			nodeInfos[from].rchild = to;
		}
		else continue;
		nodeInfos[to].edgeN = i;
		++nodesTaken;
	}
	trees += (nodes - nodesTaken);
	if (trees > 2) {
		printf("-1\n");
		return 0;
	}
	else if (trees == 1) {
		if (nodeInfos[from].parent == to) {
			std::swap(from, to);
		}
		nodeInfos[to].parent = 0;
		if (nodeInfos[from].lchild == to) nodeInfos[from].lchild = 0;
		else if (nodeInfos[from].rchild == to) nodeInfos[from].rchild = 0;
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
	print(tree1Nodes.begin(), tree1Nodes.end());
	print(tree1Edges.begin(), tree1Edges.end());
	print(tree2Nodes.begin(), tree2Nodes.end());
	print(tree2Edges.begin(), tree2Edges.end());
	putchar('\n');//sort?
}