#include <iostream>
#include <vector>
#include <stack>
#include <queue>

int main() {
	int vertice, edge, start;
	scanf_s("%d %d %d", &vertice, &edge, &start);

	std::vector<std::vector<bool>> graph(vertice, std::vector<bool>(vertice, false));
	std::vector<bool> stkVisit(vertice, true);
	std::vector<bool> qVisit(vertice, true);
	int from, to;
	for (int i = 0; i < edge; ++i) {
		scanf_s("%d %d", &from, &to);
		--from;
		--to;
		graph[from][to] = true;
		graph[to][from] = true;
	}
	int idx, next;
	std::stack<std::pair<int, int>> stk;
	stk.push(std::make_pair(start - 1, 0));
	printf("%d", start);
	stkVisit[start - 1] = false;;
	next = 0;
	while (!stk.empty()) {
		idx = stk.top().first;
		next = stk.top().second;
		int i = next;
		for (; i < vertice; ++i) {
			if (graph[idx][i] && stkVisit[i]) {
				stk.top().second = i + 1;
				stk.push(std::make_pair(i, 0));
				printf(" %d", i + 1);
				stkVisit[i] = false;
				break;
			}
		}
		if (i == vertice) stk.pop();
	}
	putchar('\n');

	printf("%d", start);
	std::queue<int> q;
	q.push(start - 1);
	qVisit[start - 1] = false;
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		for (int i = 0; i < vertice; ++i) {
			if (graph[idx][i] && qVisit[i]) {
				printf(" %d", i + 1);
				q.push(i);
				qVisit[i] = false;
			}
		}
	}
	putchar('\n');
}