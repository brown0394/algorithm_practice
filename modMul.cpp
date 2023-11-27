#include <iostream>
#include <vector>

int main() {
	int A, B, C;
	scanf_s("%d %d %d", &A, &B, &C);
	std::vector<int> including;
	long long result = 0;
	int shift = 1;
	if (B) {
		for (int i = 0; i < 32; ++i) {
			if (shift & B) including.push_back(i);
			shift <<= 1;
		}
		std::vector<long long> powers(including.back()+1);
		powers[0] = A % C;
		int end = including.back();
		int idx = 0;
		if (idx == including[0]) {
			result = powers[0];
			++idx;
		}
		else {
			result = 1;
		}
		for (int i = 1; i <= end; ++i) {
			powers[i] = (powers[i - 1] * powers[i - 1]) % C;
			if (i == including[idx]) {

				result = (result * powers[i]) % C;
				++idx;
			}
		}
	}
	printf("%lld\n", result);
}