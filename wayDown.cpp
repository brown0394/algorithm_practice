#include <iostream>
#include <vector>



int main() {
	int N;
	scanf_s("%d", &N);
	int min[3], max[3], cur[3], next[3];
	scanf_s("%d %d %d", &max[0], &max[1], &max[2]);
	min[0] = max[0];
	min[1] = max[1];
	min[2] = max[2];
	for (int i = 1; i < N; ++i) {
		scanf_s("%d %d %d", &cur[0], &cur[1], &cur[2]);
		if (max[0] > max[1]) next[0] = max[0] + cur[0];
		else next[0] = cur[0] + max[1];
		if (max[2] > max[1]) next[2] = max[2] + cur[2];
		else next[2] = max[1] + cur[2];
		if (max[1] >= max[0] && max[1] >= max[2]) next[1] = max[1] + cur[1];
		else if (max[0] >= max[1] && max[0] >= max[2]) next[1] = max[0] + cur[1];
		else next[1] = max[2] + cur[1];
		max[0] = next[0];
		max[1] = next[1];
		max[2] = next[2];

		if (min[0] < min[1]) next[0] = min[0] + cur[0];
		else next[0] = cur[0] + min[1];
		if (min[2] < min[1]) next[2] = min[2] + cur[2];
		else next[2] = min[1] + cur[2];
		if (min[1] <= min[0] && min[1] <= min[2] ) next[1] = min[1] + cur[1];
		else if (min[0] <= min[1] && min[0] <= min[2]) next[1] = min[0] + cur[1];
		else next[1] = min[2] + cur[1];
		min[0] = next[0];
		min[1] = next[1];
		min[2] = next[2];
	}
	if (max[1] > max[0]) max[0] = max[1];
	if (max[2] > max[0]) max[0] = max[2];
	if (min[1] < min[0]) min[0] = min[1];
	if (min[2] < min[0]) min[0] = min[2];
	printf("%d %d\n", max[0], min[0]);
}