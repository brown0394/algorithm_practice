#include <iostream>
#include <vector>



int main() {
	int num;
	std::vector<int> rec(100001, 100001);
	rec[1] = 1;
	rec[2] = 2;
	rec[3] = 3;
	scanf_s("%d", &num);
	for (int i = 1; i <= 316; ++i) {
		if (i * i > num) break;
		rec[i * i] = 1;
	}
	for (int i = 5; i <= num; ++i) {
		for (int j = 1; j * j <= i; ++j) {
			if (rec[i - (j * j)] + 1 < rec[i]) rec[i] = rec[i - (j * j)] + 1;
		}
	}
	
	printf("%d\n", rec[num]);
}
