#include <iostream>
#include <vector>

int main() {
	int seq, target;
	scanf_s("%d %d", &seq, &target);
	std::vector<int> sequence(seq);
	int sum = 0, right = 0;
	for (int i = 0; i < seq; ++i) {
		scanf_s("%d", &sequence[i]);
		if (sum < target) {
			sum += sequence[i];
			right = i;
		}
	}
	int left = 0;
	int min = right - left;
	if (min == (seq - 1) && sum < target) {
		printf("0\n");
		return 0;
	}
	while (true) {
		if (sum >= target) {
			if (min > right - left) min = right - left;
			sum -= sequence[left++];
		}
		else {
			if (++right == seq) break;
			sum += sequence[right];
		}
	}
	printf("%d\n", min + 1);
}