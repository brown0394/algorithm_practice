#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int elems;
	scanf_s("%d", &elems);
	std::vector<int> arr(elems);
	for (int i = 0; i < elems; ++i) {
		scanf_s("%d", &arr[i]);
	}
	if (elems < 3) {
		printf("0\n");
		return 0;
	}
	std::sort(arr.begin(), arr.end());
	int low, high;
	int count = 0;
	for (int i = 0; i < elems; ++i) {
		low = 0;
		high = elems - 1;
		while (low < high) {
			if (low == i) {
				++low;
				continue;
			}
			else if (high == i) {
				--high;
				continue;
			}
			int added = arr[low] + arr[high];
			if (added == arr[i]) {
				++count;
				break;
			}
			else if (added < arr[i]) ++low;
			else --high;
		}
	}
	printf("%d\n", count);
}