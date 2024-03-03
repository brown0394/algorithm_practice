#include <iostream>
#include <vector>

int main() {
	int num;
	scanf_s("%d", &num);
	std::vector<long long> fibo(num + 1);
	if (num) fibo[1] = 1;
	for (int i = 2; i <= num; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	printf("%lld\n", fibo[num]);
}
