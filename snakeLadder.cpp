#include <iostream>
#include <queue>

int main() {
	int snakes, ladders;
	scanf_s("%d %d", &ladders, &snakes);
	int board[101]{ 0 };
	bool visited[101]{ false };
	int idx, to;
	visited[0] = true;
	for (int i = 0; i < ladders + snakes; ++i) {
		scanf_s("%d %d", &idx, &to);
		board[idx] = to;
	}
	int count = 1;
	int now = 1;
	std::queue <std::pair<int, int>> q;
	while (true) {
		if (now + 6 >= 100) {
			break;
		}
		for (int i = 1; i <= 6; ++i) {
			if (visited[now + i]) continue;
			if (!board[now + i]) {
				q.push(std::make_pair(now + i, count));
				visited[now + i] = true;
			}
			else {
				q.push(std::make_pair(board[now + i], count));
				visited[board[now + i]] = true;
			}
		}
		now = q.front().first;
		count = q.front().second;
		q.pop();
		++count;
	}
	printf("%d\n", count);
}