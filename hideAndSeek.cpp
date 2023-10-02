#include <iostream>
#include <queue>

int main() {
	int start, target;
	scanf_s("%d %d", &start, &target);
	std::queue<std::pair<int, int>> q;

	std::vector<bool> visited(target + start + 1, false);
	int leastBiggest = target + 2;
	if (start == target) {
		printf("0\n");
	}
	else {
		int count = 0;
		visited[start] = true;
		while (true) {
			if (start << 1 == target) break;
			int mul = start << 1;
			if (mul < leastBiggest && !visited[mul]) {
				q.push(std::make_pair(mul, count + 1));
				visited[mul] = true;
			}
			if (start + 1 == target) break;
			if (start < target && !visited[start + 1]) {
				q.push(std::make_pair(start + 1, count + 1));
				visited[start + 1] = true;
			}
			if (start - 1 == target) break;
			if (start > 0 && !visited[start - 1]) {
				q.push(std::make_pair(start - 1, count + 1));
				visited[start - 1] = true;
			}

			start = q.front().first;
			count = q.front().second;
			q.pop();
		}
		printf("%d\n", ++count);
	}
}