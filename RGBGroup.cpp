#include <iostream>
#include <vector>
#include <queue>

void checkVisited(std::vector<std::vector<short int>>& visited, std::vector<std::vector<char>>& arr, std::queue<std::pair<int, int>>& q,
	int i, int j, int n) {
	short int flag = 1;
	q.push(std::make_pair(i, j));
	if (arr[i][j] == 'B') flag = 3;
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();
		if (j + 1 < n && !visited[i][j + 1] && arr[i][j] == arr[i][j + 1]) {
			q.push(std::make_pair(i, j + 1));
			visited[i][j + 1] = flag;
		}
		if (i + 1 < n && !visited[i + 1][j] && arr[i][j] == arr[i + 1][j]) {
			q.push(std::make_pair(i + 1, j));
			visited[i + 1][j] = flag;
		}
		if (j - 1 >= 0 && !visited[i][j - 1] && arr[i][j] == arr[i][j - 1]) {
			q.push(std::make_pair(i, j - 1));
			visited[i][j - 1] = flag;
		}
		if (i - 1 >= 0 && !visited[i - 1][j] && arr[i][j] == arr[i - 1][j]) {
			q.push(std::make_pair(i - 1, j));
			visited[i - 1][j] = flag;
		}
	}
}

void checkRGVisited(std::vector<std::vector<short int>>& visited, std::vector<std::vector<char>>& arr, std::queue<std::pair<int, int>>& q,
	int i, int j, int n) {
	short int flag = 3;
	q.push(std::make_pair(i, j));
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();
		if (j + 1 < n && visited[i][j + 1] < 3 && (arr[i][j + 1] == 'R' || arr[i][j + 1] == 'G')) {
			q.push(std::make_pair(i, j + 1));
			visited[i][j + 1] = flag;
		}
		if (i + 1 < n && visited[i + 1][j] < 3 && (arr[i + 1][j] == 'R' || arr[i + 1][j] == 'G')) {
			q.push(std::make_pair(i + 1, j));
			visited[i + 1][j] = flag;
		}
		if (j - 1 >= 0 && visited[i][j - 1] < 3 && (arr[i][j - 1] == 'R' || arr[i][j - 1] == 'G')) {
			q.push(std::make_pair(i, j - 1));
			visited[i][j - 1] = flag;
		}
		if (i - 1 >= 0 && visited[i - 1][j] < 3 && (arr[i - 1][j] == 'R' || arr[i - 1][j] == 'G')) {
			q.push(std::make_pair(i - 1, j));
			visited[i - 1][j] = flag;
		}
	}
}

int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<std::vector<char>> arr(n, std::vector<char>(n));

	for (int i = 0; i < n; ++i) {
		getchar();
		for (int j = 0; j < n; ++j) {
			scanf_s("%c", &arr[i][j]);
		}
	}
	std::queue<std::pair<int, int>> q;
	std::vector<std::vector<short int>> visited(n, std::vector<short int>(n, 0));
	int R = 0;
	int G = 0;
	int RG = 0;
	int B = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visited[i][j]) {
				switch (arr[i][j]) {
				case 'R': {++R;	visited[i][j] = 1; break; }
				case 'G': {++G; visited[i][j] = 1; break; }
				case 'B': {++B; visited[i][j] = 3; break; }
				}
				checkVisited(visited, arr, q, i, j, n);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visited[i][j] < 3) {
				switch (arr[i][j]) {
				case 'R': 
				case 'G': {++RG; visited[i][j] = 3; break; }
				}
				checkRGVisited(visited, arr, q, i, j, n);
			}
		}
	}

	printf("%d %d\n", R + G + B, RG + B);
}