#include <iostream>

int main() {
	int in;
	int stk[10000];
	int idx = 1;
	scanf_s("%d", &stk[0]);
	while (std::cin >> in) {//scanf_s("%d", &in) != EOF) {
		if (in > stk[idx - 1]) {
			--idx;
			while (idx) {
				if (stk[idx - 1] < in) {
					if (stk[idx - 1] > stk[idx]) {
						printf("%d\n", stk[idx--]);
					}
					else {
						int i = idx - 1;
						while (i) {
							if (stk[i] < stk[i - 1]) {
								if (in > stk[i - 1]) {
									for (; idx >= i; --idx) {
										printf("%d\n", stk[idx]);
									}
								}
								break;
							}
							--i;
						}
						break;
					}
				}
				else {
					break;
				}
			}
			++idx;
		}
		stk[idx++] = in;
	}
	for (--idx; idx >= 0; --idx) {
		printf("%d\n", stk[idx]);
	}
}