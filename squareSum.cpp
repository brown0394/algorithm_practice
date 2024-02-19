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
		rec[i * i] = 1;
	}

	for (int i = 4; i <= num; ++i) {
		int low = 1;
		int high = i - 1;
		while (low <= high) {
			if (rec[i] > rec[low] + rec[high]) rec[i] = rec[low] + rec[high];
			++low;
			--high;
		}
	}
	
	printf("%d\n", rec[num]);
}
