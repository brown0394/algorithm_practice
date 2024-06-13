#include <iostream>


int main() {
	int testCases;
	scanf_s("%d", &testCases);
	char c;
	getchar();
	for (int i = 0; i < testCases; ++i) {
		c = getchar();
		char last = 0;
		int found = 0;
		while (c != '\n') {
			if ((c == 'p' || c == 'P') && last != 'l') last = 'p';
			else if ((c == 'l' || c == 'L') && last == 'p') {
				last = 'l';
			}
			else if ((c == 'u' || c == 'U') && last == 'l') {
				++found;
				last = 0;
			}
			c = getchar();
		}
		printf("%d\n", found);
	}
}