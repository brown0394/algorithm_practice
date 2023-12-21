#include <iostream>
#include <vector>
#include <map>

class Fibo {
private:
	long long modval;
	std::map<long long, long long> fiboMap;
	long long findAndInsert(long long target);
public:
	Fibo(long long p_modval);
	long long dOcagne(long long target);
};

Fibo::Fibo(long long p_modval) : modval(p_modval) {
	fiboMap.insert({ 0, 0 });
	fiboMap.insert({ 1, 1 });
	long long temp;
	long long first = 0, second = 1;

	for (long long i = 2; i < 11; ++i) {
		temp = first;
		first = second;
		second = (temp + second);
		fiboMap.insert({ i, second });
	}
}

long long Fibo::findAndInsert(long long target) {
	auto found = fiboMap.find(target);
	if (found != fiboMap.end()) return found->second;
	long long val = dOcagne(target);
	fiboMap.insert({ target, val });
	return val;
}

long long Fibo::dOcagne(long long target) {
	if (target == 0) return 0;
	if (target == 1) return 1;
	long long m, n, a, b, c, d, retval;
	m = target >> 1;
	n = m + (target % 2);
	a = findAndInsert(m - 1);
	b = findAndInsert(m);
	if (n == m) {
		c = findAndInsert(m + 1);
		retval = (((a * b) % modval) + ((b * c) % modval)) % modval;
	}
	else {
		c = findAndInsert(n);
		d = findAndInsert(n + 1);
		retval = (((a * c) % modval) + ((b * d) % modval)) % modval;
	}
	return retval;
}

int main() {
	long long n;
	scanf_s("%lld", &n);
	Fibo fibo(1000000007);
	printf("%lld\n", fibo.dOcagne(n));
}