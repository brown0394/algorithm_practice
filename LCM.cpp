#include <iostream>

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	for (int i = 0; i < testCases; ++i) {
		int one, two;
		scanf_s("%d %d", &one, &two);
		long long oneIncr = one;
		long long twoIncr = two;
		while (oneIncr != twoIncr){
			if (oneIncr < twoIncr) oneIncr += one;
			else if (twoIncr < oneIncr) twoIncr += two;
		}
		printf("%lld\n", oneIncr);
	}
}
