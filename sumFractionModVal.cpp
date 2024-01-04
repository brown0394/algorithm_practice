#include <iostream>
#include <vector>

#define MODVAL 1000000007
class fracMod {
private:
	int mod;
	std::vector<int> including;
public:
	fracMod(int p_mod);
	long long getPow(int coef);
};

fracMod::fracMod(int p_mod) :mod(p_mod) {
	int shift = 1;
	p_mod -= 2;
	for (int i = 0; i < 32; ++i) {
		if (shift & p_mod) including.push_back(i);
		shift <<= 1;
	}
}
long long fracMod::getPow(int coef) {
	long long result = 0;
	std::vector<long long> powers(including.back() + 1);
	powers[0] = coef % mod;
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
		powers[i] = (powers[i - 1] * powers[i - 1]) % mod;
		if (i == including[idx]) {
			result = (result * powers[i]) % mod;
			++idx;
		}
	}
	return result;
}

int main() {
	int dices, denominator, numerator;
	scanf_s("%d", &dices);
	fracMod fm(MODVAL);
	long long result = 0;
	for (int i = 0; i < dices; ++i) {
		scanf_s("%d %d", &denominator, &numerator);
		result = (result + (fm.getPow(denominator) * (long long)numerator) % MODVAL) % MODVAL;
	}
	
	
	printf("%lld\n", result);
}