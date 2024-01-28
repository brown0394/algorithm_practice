#include <iostream>
#include <vector>

int main() {
	int tower;
	scanf_s("%d", &tower);
	std::vector<int> towers(tower + 1);
	std::vector<int> signaled(tower + 1);
	int highest = 0;
	for (int i = 1; i <= tower; ++i) {
		scanf_s("%d", &towers[i]);
		if (towers[i] > towers[highest]) {
			highest = i;
			signaled[i] = 0;
		}
		else {
			int idx = i - 1;
			if (towers[idx] > towers[i]) signaled[i] = idx;
			else {
				while (signaled[idx] && towers[signaled[idx]] < towers[i]) idx = signaled[idx];
				signaled[i] = signaled[idx];
			}
		}
	}
	printf("0");
	for (int i = 2; i <= tower; ++i) {
		printf(" %d", signaled[i]);
	}
	printf("\n");
}
