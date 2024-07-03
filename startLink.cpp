#include <iostream>
#include <queue>
#include <bitset>

struct floorInfo {
	int floor, move;
};

int bfs(int floors, int start, int goal, int up, int down) {
	std::bitset<1000001> visited;
	visited[start] = true;
	std::queue<floorInfo> q;
	q.push({ start, 0});
	int cur, move;
	while (!q.empty()) {
		cur = q.front().floor;
		move = q.front().move + 1;
		q.pop();
		if (cur + up <= floors && !visited[cur + up]) {
			if (cur + up == goal) return move;
			visited[cur + up] = true;
			q.push({ cur + up, move });
		}
		if (cur - down > 0 && !visited[cur - down]) {
			if (cur - down == goal) return move;
			visited[cur - down] = true;
			q.push({ cur - down, move });
		}
	}
	return -1;
}

int main() {
	int floors, start, goal, up, down;
	scanf_s("%d %d %d %d %d", &floors, &start, &goal, &up, &down);
	int result;
	if (start == goal) result = 0;
	else result = bfs(floors, start, goal, up, down);
	if (result < 0) printf("use the stairs\n");
	else printf("%d\n", result);
}