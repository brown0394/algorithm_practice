#include <iostream>
#include <vector>

int main() {
	std::vector<long long> combSums(91);
	combSums[0] = 1;
	combSums[1] = 1;
	int in;
	scanf_s("%d", &in);
	for (int i = 2; i < in; ++i) {
		combSums[i] = combSums[i - 1] + combSums[i - 2];
	}
	printf("%lld\n", combSums[in - 1]);
}
