#include <iostream>
#include <vector>
#include <stack>

void dfs(std::vector<int>& answer, std::vector<int>* tree, int cur) {
	std::stack<std::pair<int, int>>stk;
	int level = 1;
	answer[cur] = level;
	int idx = 0;
	int root = cur;
	while (true) {
		if (tree[cur].size() > idx) {
			if (!stk.empty() && tree[cur][idx] == stk.top().first) {
				++idx;
			}
			else {
				stk.push(std::make_pair(cur, idx + 1));
				cur = tree[cur][idx];
				++level;
				answer[cur] = level;
			}
		}
		else {
			if (cur == root) break;
			auto p = stk.top();
			--level;
			idx = p.second;
			cur = p.first;
			stk.pop();
		}
	}
}

void solve(std::vector<std::vector<int>> prob, int v) {
	std::vector<int> answer(v);
	std::vector<int>* tree = new std::vector<int>[v];

	for (auto it = prob.begin(); it != prob.end(); ++it) {
		tree[(*it)[0]].push_back((*it)[1]);
		tree[(*it)[1]].push_back((*it)[0]);
	}

	int max = 0;
	for (int i = 0; i < v; ++i) {
		if (tree[i].size() > max) max = tree[i].size();
	}
	int root = 0;
	for (int i = 0; i < v; ++i) {
		if (tree[i].size() == max - 1) {
			root = i;
			break;
		}
	}
	dfs(answer, tree, root);
	for (auto it = answer.begin(); it != answer.end(); ++it) {
		printf("%d ", *it);
	}
	putchar('\n');

	delete[] tree;
}

int main() {
	std::vector<std::vector<int>> prob {{3, 4}, { 6, 2 }, { 0, 4 }, { 4, 5 }, { 2, 1 }, { 2, 3 }};
	int v = 7;
	solve(prob, v);

}