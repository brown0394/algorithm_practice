#include <iostream>
#include <vector>

int main() {
	int testCases;
	scanf("%d", &testCases);
	int in;
	for (int i = 0; i < testCases; ++i) {
		scanf("%d", &in);
		int val = (in >> 1) + 1 + (in / 3);
		int cur = in - 3;
		while (cur > 1) {
			val += (cur >> 1);
			cur -= 3;
		}
        printf("%d\n", val);
	}
}