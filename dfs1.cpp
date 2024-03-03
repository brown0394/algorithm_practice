#include <iostream>
#include <vector>
#include <set>

std::vector<std::set<int>> connections;
std::vector<int> visitSeq;
int seq;
void dfs(int cur) {
	for (auto it = connections[cur].begin(); it != connections[cur].end(); ++it) {
		if (!visitSeq[*it]) {
			visitSeq[*it] = seq++;
			dfs(*it);
		}
	}
}

int main() {
	int vertexes, edges, start;
	seq = 2;
	scanf_s("%d %d %d", &vertexes, &edges, &start);
	connections.resize(vertexes + 1);
	visitSeq.resize(vertexes + 1);
	visitSeq[start] = 1;
	int from, to;
	for (int i = 0; i < edges; ++i) {
		scanf_s("%d %d", &from, &to);
		connections[from].insert(to);
		connections[to].insert(from);
	}
	dfs(start);
	for (int i = 1; i <= vertexes; ++i) {
		printf("%d\n", visitSeq[i]);
	}
}
