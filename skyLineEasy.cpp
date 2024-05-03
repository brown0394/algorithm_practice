#include <iostream>
#include <vector>
#include <stack>

int main() {
	int n;
	scanf_s("%d", &n);
	int x, y;
	std::stack<int> stk;
	stk.push(0);
	int buildings = 0;
	for (int i = 0; i < n; ++i) {
		scanf_s("%d %d", &x, &y);
		while (y != stk.top()) {
			if (stk.top() < y) {
				++buildings;
				stk.push(y);
				break;
			}
			else stk.pop();
		}
	}
	printf("%d\n", buildings);
}