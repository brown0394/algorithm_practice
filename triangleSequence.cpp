#include <iostream>
#include <vector>

int main() {
	int N, testCases;
	std::vector<long long> triangles(3, 1);
	scanf_s("%d", &testCases);
	int idx;
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d", &N);
		idx = triangles.size();
		if (idx < N) {
			for (int j = idx; j < N; ++j) {
				triangles.push_back(triangles[j - 2] + triangles[j - 3]);
			}
		}
		printf("%lld\n", triangles[N - 1]);
	}
}