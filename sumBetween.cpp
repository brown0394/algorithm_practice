#include <iostream>
#include <vector>

int main() {
	int numbers, cases;
	scanf_s("%d %d", &numbers, &cases);

	std::vector<int>arr(numbers);
	scanf_s("%d", &arr[0]);
	for (int i = 1; i < numbers; ++i) {
		scanf_s("%d", &arr[i]);
		arr[i] = arr[i] + arr[i - 1];
	}

	int j, k;
	for (int i = 0; i < cases; ++i) {
		scanf_s("%d %d", &j, &k);
		if (j == 1) {
			printf("%d\n", arr[k - 1]);
		}
		else {
			printf("%d\n", arr[k - 1] - arr[j - 2]);
		}
	}
}