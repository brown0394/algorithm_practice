#include <iostream>
#include <vector>
#include <queue>


int main() {
	int vertex, edge;
	scanf_s("%d %d", &vertex, &edge);
	std::vector<bool> visited(vertex+1, false);
	std::vector<std::vector<int>> graph(vertex+1);

	int from, to;
	for (int i = 0; i < edge; ++i) {
		scanf_s("%d %d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	std::queue<int> q;
	int count = 0;
	for (int i = 1; i <= vertex; ++i) {
		if (visited[i]) continue;
		q.push(i);
		visited[i] = true;
		++count;
		while (!q.empty()) {
			from = q.front();
			q.pop();
			for (auto it = graph[from].begin(); it != graph[from].end(); ++it) {
				if (!visited[*it]) {
					q.push(*it);
					visited[*it] = true;
				}
			}
		}
	}

	printf("%d\n", count);

}