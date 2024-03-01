#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

struct node {
	int i;
	int j;
};
int size;
int maxHeight;
std::vector<std::vector<int>> terrains;
std::vector<std::bitset<101>> visited;
void markMap() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			scanf("%d", &terrains[i][j]);
			if (terrains[i][j] > maxHeight) maxHeight = terrains[i][j];
		}
	}
}

void markConnectedLands(std::queue<node>& q, int height) {
	int i, j;
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		q.pop();
		if (i + 1 < size && !visited[i + 1][j] && terrains[i + 1][j] > height) {
			visited[i + 1][j] = true;
			q.push({ i + 1, j });
		}
		if (j + 1 < size && !visited[i][j + 1] && terrains[i][j + 1] > height) {
			visited[i][j + 1] = true;
			q.push({ i, j + 1 });
		}
		if (i && !visited[i - 1][j] && terrains[i - 1][j] > height) {
			visited[i - 1][j] = true;
			q.push({ i - 1, j });
		}
		if (j && !visited[i][j - 1] && terrains[i][j - 1] > height) {
			visited[i][j - 1] = true;
			q.push({ i, j - 1 });
		}
	}
}

int countSafeZones(int height) {
	int safeZones = 0;
	std::queue<node> q;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (terrains[i][j] > height && !visited[i][j]) {
				q.push({ i, j });
				visited[i][j] = true;
				++safeZones;
				markConnectedLands(q, height);
			}
		}
	}
	return safeZones;
}

int main() {
	scanf("%d", &size);
	maxHeight = 0;
	terrains.resize(size, std::vector<int>(size));
	markMap();
	int safeZones = 1, maxSafeZones = 1;
	for (int i = 1; i < maxHeight; ++i) {
		visited.resize(size);
		safeZones = countSafeZones(i);
		if (safeZones > maxSafeZones) maxSafeZones = safeZones;
		visited.clear();
	}
	printf("%d\n", maxSafeZones);
}
