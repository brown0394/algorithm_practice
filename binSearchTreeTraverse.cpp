#include <iostream>

int main() {
	int in;
	int stk[10000];
	int idx = 0;
	while (std::cin >> in) {//scanf_s("%d", &in) != EOF) {
		if (idx) {
			if (in > stk[idx - 1]) {
				--idx;
				while (idx) {
					if (stk[idx - 1] < in) {
						printf("%d\n", stk[idx--]);
					}
					else {
						break;
					}
				}
				++idx;
			}
		}
		stk[idx++] = in;
	}
	for (--idx; idx >= 0; --idx) {
		printf("%d\n", stk[idx]);
	}
}