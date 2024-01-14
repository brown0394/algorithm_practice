#include <iostream>

int main() {
	int num;
	scanf_s("%d", &num);
	int in;
	int count = 0;
	for (int i = 0; i < 5; ++i) {
		scanf_s("%d", &in);
		if (in % 10 == num) ++count;
	}
	printf("%d\n", count);
}
