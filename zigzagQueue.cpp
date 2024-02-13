#include <iostream>
#include <vector>
#include <bitset>

std::bitset<101> visited;
int posCount;
int size;


void dfs(int depth, int num, bool bigger) {
	if (depth == size) {
		posCount = (posCount + 1) % 1000000;
		return;
	}
	if (bigger) {
		for (int i = num + 1; i <= size; ++i) {
			if (!visited[i]) {
				visited[i] = true;
				dfs(depth + 1, i, !bigger);
				visited[i] = false;
			}
		}
		return;
	}
	else {
		for (int i = num - 1; i >= 1; --i) {
			if (!visited[i]) {
				visited[i] = true;
				dfs(depth + 1, i, !bigger);
				visited[i] = false;
			}
		}
	}
}

void countPossiblity() {
	posCount = 0;
	if (size == 1) {
		posCount = 1;
		return;
	}
	for (int i = 1; i <= size; ++i) {
		visited[i] = true;
		dfs(1, i, true);
		dfs(1, i, false);
		visited[i] = false;
	}
}

int main() {
	scanf("%d", &size);
	countPossiblity();
	printf("%d\n", posCount);
}
