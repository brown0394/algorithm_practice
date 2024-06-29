#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <deque>

struct node {
	int root;
	std::list<int> children;
	std::list<int> edges;
};

void adoptTree(std::vector<node>& nodeInfos, int newRoot, int oldRoot, int newEdgeN) {
	while (!nodeInfos[oldRoot].children.empty()) {
		nodeInfos[nodeInfos[oldRoot].children.back()].root = newRoot;
		nodeInfos[newRoot].children.push_back(nodeInfos[oldRoot].children.back());
		nodeInfos[oldRoot].children.pop_back();
	}
	nodeInfos[newRoot].edges.splice(nodeInfos[newRoot].edges.end(), nodeInfos[oldRoot].edges);
}

void print(std::list<int>& v) {
	printf("\n");
	if (v.empty()) return;
	v.sort();
	auto it = v.begin();
	printf("%d", *it++);
	for (auto end = v.end(); it != end; ++it) printf(" %d", *it);
}

int main() {
	int nodes, edges;
	scanf_s("%d %d", &nodes, &edges);
	std::vector<node> nodeInfos(nodes + 1, { 0 });
	std::vector<int> visitCount(nodes + 1);
	std::vector<std::pair<int, int>> edgeArr(edges + 1);
	int trees = 0;
	int nodesTaken = 0;
	int from, to;
	for (int i = 1; i <= edges; ++i) {
		scanf_s("%d %d", &from, &to);
		edgeArr[i].first = from;
		edgeArr[i].second = to;
		if (nodeInfos[from].root && nodeInfos[to].root) {
			int root1 = nodeInfos[from].root, root2 = nodeInfos[to].root;
			if (root1 == root2) continue;
			if (nodeInfos[root1].children.size() >= nodeInfos[root2].children.size()) {
				adoptTree(nodeInfos, nodeInfos[from].root, nodeInfos[to].root, i);
			}
			else {
				adoptTree(nodeInfos, nodeInfos[to].root, nodeInfos[from].root, i);
			}
			--trees;
			continue;
		}
		else if (!nodeInfos[from].root && nodeInfos[to].root) {
			std::swap(from, to);
		}
		else if (!nodeInfos[from].root && !nodeInfos[to].root) {
			if (from > to) {
				std::swap(from, to);
			}
			nodeInfos[from].root = from;
			nodeInfos[from].children.push_back(from);
			if (!visitCount[to] && !visitCount[from]) ++trees;
		}

		nodeInfos[to].root = nodeInfos[from].root;
		nodeInfos[nodeInfos[from].root].children.push_back(to);
		nodeInfos[nodeInfos[from].root].edges.push_back(i);
		if (!visitCount[to]++) ++nodesTaken;
		if (!visitCount[from]++) ++nodesTaken;

	}
	trees += (nodes - nodesTaken);
	if (trees > 2) {
		printf("-1\n");
		return 0;
	}
	else if (trees == 1) {
		for (auto it = nodeInfos[nodeInfos[1].root].edges.begin(),
			end = nodeInfos[nodeInfos[1].root].edges.end(); it != end; ++it) {
			int leaf = 0;
			if (visitCount[edgeArr[*it].first] == 1) {
				leaf = edgeArr[*it].first;
			}
			else if (visitCount[edgeArr[*it].second] == 1) {
				leaf = edgeArr[*it].second;
			}
			if (leaf) {
				int p = nodeInfos[leaf].root;
				nodeInfos[leaf].root = leaf;
				nodeInfos[leaf].children.push_back(leaf);
				nodeInfos[leaf].edges.push_back(*it);
				nodeInfos[p].children.remove(leaf);
				nodeInfos[p].edges.erase(it);
				break;
			}
		}
	}
	int one = 0, two = 0;
	for (int i = 1; i <= nodes; ++i) {
		if (nodeInfos[i].root == i) {
			if (!one) one = i;
			else {
				two = i;
				break;
			}
		}
	}
	printf("%d %d", nodeInfos[one].children.size(), nodeInfos[two].children.size());
	print(nodeInfos[one].children);
	print(nodeInfos[one].edges);
	print(nodeInfos[two].children);
	print(nodeInfos[two].edges);
	putchar('\n');
}