#include <iostream>
#include <vector>


int main() {
	int target;
	scanf_s("%d", &target);
	std::vector<int> arr(1025, 2000);
	int num, count;
	for (int i = 2; i <= target; ++i) {
		if (arr[i] > i) arr[i] = i;
		if (arr[i] > arr[i + 1] + 1) arr[i] = arr[i + 1] + 1;
		num = i << 1;
		count = arr[i] + 2;
		while (num <= target) {
			if (arr[num] > count) arr[num] = count;
			num += i;
			++count;
		}
		if (arr[target] > count + (num - target)) arr[target] = count + (num - target);
	}
	printf("%d\n", arr[target]);
}
