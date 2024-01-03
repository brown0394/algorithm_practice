#include <iostream>
#include <queue>

int main() {
	int start, target;
	scanf("%d %d", &start, &target);

	if (start == target) printf("0\n1\n");
	else if (start > target) printf("%d\n1\n", start - target);
	else {
		int count = 0;
		int found = 0, possibleWays = 0;
		std::queue<std::pair<int, int>> q;
		std::vector<int> visited(target + 3, 200000);
		int leastBiggest = target + 2;
		visited[start] = 0;
		while (true) {
			if (found && count >= found) break;
			if (start << 1 == target || start + 1 == target || start - 1 == target) {
				if (!found) found = count + 1;
				++possibleWays;
			}
			if (!found) {
				int mul = start << 1;
				if (mul < leastBiggest && visited[mul] > count) {
					q.push(std::make_pair(mul, count + 1));
					visited[mul] = count + 1;
				}
				if (start < target && visited[start + 1] > count) {
					q.push(std::make_pair(start + 1, count + 1));
					visited[start + 1] = count + 1;
				}
				if (start && visited[start - 1] > count) {
					q.push(std::make_pair(start - 1, count + 1));
					visited[start - 1] = count + 1;
				}
			}
			if (q.empty()) break;
			start = q.front().first;
			count = q.front().second;
			q.pop();
		}
		printf("%d\n%d\n", found, possibleWays);
	}
}