#include <iostream>

int main() {
	int num;
	scanf_s("%d", &num);
	int in;
	int sum = 0;
	int killStreak = 1;
	for (int i = 0; i < num; ++i) {
		scanf_s("%d", &in);
		if (in) sum += killStreak++;
		else killStreak = 1;
	}
	printf("%d\n", sum);
}
