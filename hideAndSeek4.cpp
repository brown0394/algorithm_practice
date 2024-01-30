#include <iostream>
#include <queue>
#include <stack>

struct node {
	int last;
	int count;
};

int main() {
	int start, target;
	scanf_s("%d %d", &start, &target);

	if (start == target) printf("0\n%d\n", start);
	else if (start > target) {
		printf("%d\n%d", start - target, start);
		for (int i = start - 1; i >= target; --i) {
			printf(" %d", i);
		}
		printf("\n");
	}
	else {
		int count = 0;
		std::queue<std::pair<int, int>> q;
		std::vector<node> visited(target + 3, node{0, 20000});
		int leastBiggest = target + 2;
		visited[start].count = 0;
		int cur = start;
		std::stack<int> answer;
		while (true) {
			if (cur << 1 == target || cur + 1 == target || cur - 1 == target) {
				if (cur << 1 == target) answer.push(cur << 1);
				else if (cur + 1 == target) answer.push(cur + 1);
				else answer.push(cur - 1);
				answer.push(cur);
				if (cur == start) {
					answer.push(count + 1);
					break;
				}
				while (visited[cur].last != start) {
					cur = visited[cur].last;
					answer.push(cur);
				}
				answer.push(visited[cur].last);
				answer.push(count + 1);
				break;
			}
			int mul = cur << 1;
			if (mul < leastBiggest && visited[mul].count > count) {
				q.push(std::make_pair(mul, count));
				visited[mul].count = count;
				visited[mul].last = cur;
			}
			if (cur < target && visited[cur + 1].count > count) {
				q.push(std::make_pair(cur + 1, count));
				visited[cur + 1].count = count;
				visited[cur + 1].last = cur;
			}
			if (cur && visited[cur - 1].count > count) {
				q.push(std::make_pair(cur - 1, count));
				visited[cur - 1].count = count;
				visited[cur - 1].last = cur;
			}
			if (q.empty()) break;
			cur = q.front().first;
			count = q.front().second + 1;
			q.pop();
		}
		printf("%d\n", answer.top());
		answer.pop();
		printf("%d", answer.top());
		answer.pop();
		while (!answer.empty()) {
			printf(" %d", answer.top());
			answer.pop();
		}
		printf("\n");
	}
	
}