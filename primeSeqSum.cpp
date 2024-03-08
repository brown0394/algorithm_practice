#include <iostream>
#include <vector>

int main() {
	int target;
	scanf_s("%d", &target);
	if (target == 1) {
		printf("0\n");
		return 0;
	}
	else if (target == 2) {
		printf("1\n");
		return 0;
	}
	std::vector<int> seq(target + 1);
	int len = 1;
	seq[2] = 2;
	seq[0] = 2;
	for (int i = 3; i <= target; i += 2) {
		seq[i] = i;
	}
	for (int i = 3; i <= target; ++i) {
		if (seq[i]) {
			seq[len++] = seq[i];
			for (int j = seq[i] + seq[i]; j <= target; j += seq[i]) {
				seq[j] = 0;
			}
		}
	}

	int count = 0;
	int i = 0;
	int j = 1;
	int sum = seq[i] + seq[j];
	while (true) {
		if (sum == target) {
			++count;
			sum -= seq[i++];
			if (i == j) break;
		}
		else if (sum > target) {
			sum -= seq[i++];
			if (i == j) break;
		}
		else {
			++j;
			if (j == len) break;
			sum += seq[j];
		}
	}
	if (seq[len-1] == target) ++count;
	printf("%d\n", count);
}
