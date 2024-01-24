#include <iostream>
#include <queue>

#define INF 1000000

struct node {
	int dist;
	int to;
};

int main() {
	int people;
	scanf_s("%d", &people);
	std::vector<std::vector<int>> relatives(people + 1, std::vector<int>(people + 1, INF));
	int me, target;
	scanf_s("%d %d", &me, &target);
	int edges;
	scanf_s("%d", &edges);
	int from, to;
	std::queue<node> q;
	for (int i = 0; i < edges; ++i) {
		scanf_s("%d %d", &from, &to);
		relatives[from][to] = 1;
		relatives[to][from] = 1;
		if (from == me) q.push({ 1, to });
		else if (to == me) q.push({ 1, from });
	}
	int dist;
	while (!q.empty()) {
		dist = q.front().dist;
		to = q.front().to;
		q.pop();
		for (int i = 1; i <= people; ++i) {
			if (relatives[me][i] > relatives[to][i] + dist) {
				relatives[me][i] = relatives[to][i] + dist;
				q.push({ relatives[me][i], i });
			}
		}
	}
	if (relatives[me][target] == INF) printf("-1\n");
	else printf("%d\n", relatives[me][target]);
}
