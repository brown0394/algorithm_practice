#include <iostream>
#include <cstring>

int main() {
	int testCases;
	char str[21];
	scanf_s("%d", &testCases);
	getchar();
	char c;
	for (int i = 0; i < testCases; ++i) {
		while (true) {
			scanf_s("%s%c", str, 21, &c, 1);
			for (int j = strlen(str) - 1; j >= 0; --j) {
				printf("%c", str[j]);
			}
			printf("%c", c);
			if (c == '\n') break;
		}

	}
}
