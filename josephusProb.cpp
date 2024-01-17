#include <iostream>
#include <string>

int main() {
	int num, gap;
	scanf_s("%d %d", &num, &gap);
	int josephus[5002];
	for (int i = 0; i < num; ++i) {
		josephus[i] = i + 1;
	}
	--gap;
	int idx = gap % num;
	printf("<%d", josephus[idx]);
	memmove(&josephus[idx], &josephus[idx + 1], (num - 1 - idx) * 4);
	--num;
	while (num) {
		idx = (idx + gap) % num;
		printf(", %d", josephus[idx]);
		memmove(&josephus[idx], &josephus[idx + 1], (num - 1 - idx) * 4);
		--num;
	}
	printf(">\n");
}
