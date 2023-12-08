#include <iostream>
#include <vector>
#include <queue>
#include <bitset>


struct node {
	int count;
	int loc;
};
int main() {
	int start, end;
	scanf_s("%d %d", &start, &end);
	int len;
	if (start > end) len = start;
	else len = end;
	std::vector<std::bitset<1>> visited((len + 1) << 1);
	std::queue<node> q;
	q.push(node{ 0, start });
	visited[start][0] = true;
	bool found;
	int count, loc, maxCount = 2000000;
	if (end != start) {
		while (!q.empty()) {
			loc = q.front().loc;
			count = q.front().count;
			q.pop();
			if (loc < end) {
				int shifted = loc;
				found = false;
				do {
					shifted <<= 1;
					if (shifted == end) {
						printf("%d\n", count);
						found = true;
						break;
					}
					if (!visited[shifted][0]) {
						q.push(node{ count, shifted });
						visited[shifted][0] = true;
					}
					else {
						break;
					}
				} while (shifted <= end);
				if (found) break;
			}
			if (loc - 1 == end) {
				printf("%d\n", count + 1);
				break;
			}
			if ((loc - 1) >= 0 && !visited[loc - 1][0]) {
				q.push(node{ count + 1, loc - 1 });
				visited[loc - 1][0] = true;
			}
			if (loc + 1 == end) {
				printf("%d\n", count + 1);
				break;
			}
			if (loc < end && !visited[loc + 1][0]) {
				q.push(node{ count + 1, loc + 1 });
				visited[loc + 1][0] = true;
			}

		}
	}
	else printf("0\n");
	
}