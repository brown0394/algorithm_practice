#include <iostream>
#include <vector>

int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<int> arr(n);
	int maxElem = 0;
	for (int i = 0; i < n; ++i) {
		scanf_s("%d", &arr[i]);
		if (maxElem < arr[i]) maxElem = arr[i];
	}
	std::vector<int> counter(maxElem + 1);
	int sum = n;
	++counter[arr[0]] == 1;
	int numsInSet = 1;
	bool forward = true;
	--n;
	for (int i = 1; i <= n; ++i) {
		if (forward) {
			if (++counter[arr[i]] == 1) ++numsInSet;
			if (numsInSet == i + 1) ++sum;
			for (int j = i + 1; j <= n; ++j) {
				if (--counter[arr[j - i - 1]] == 0) --numsInSet;
				if (++counter[arr[j]] == 1) ++numsInSet;
				if (numsInSet == i + 1) ++sum;
			}
		}
		else {
			if (++counter[arr[n-i]] == 1) ++numsInSet;
			if (numsInSet == i + 1) ++sum;
			for (int j = n - (i + 1); j >= 0; --j) {
				if (--counter[arr[j + i + 1]] == 0) --numsInSet;
				if (++counter[arr[j]] == 1) ++numsInSet;
				if (numsInSet == i + 1) ++sum;
			}
		}
		forward = !forward;
	}
	printf("%d\n", sum);
}