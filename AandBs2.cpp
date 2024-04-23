#include <iostream>
#include <string>
#include <bitset>

std::bitset<51> tbits;
std::bitset<51> sbits;
int sSize;

void setBit(std::string& str, std::bitset<51>& bits) {
	for (int i = 0, size = str.size(); i < size; ++i) {
		if (str[i] == 'B') bits[i] = true;
	}
}

void reverseBit(std::bitset<51>& bits, int size) {
	int half = size >> 1;
	int idx = 0;
	bool temp;
	if (size % 2) {
		++idx;
		for (; (half + idx) < size; ++idx) {
			temp = bits[half + idx];
			bits[half + idx] = bits[half - idx];
			bits[half - idx] = temp;
		}
	}
	else {
		for (; (half + idx) < size; ++idx) {
			temp = bits[half + idx];
			bits[half + idx] = bits[half - idx - 1];
			bits[half - idx - 1] = temp;
		}
	}
}

bool subAB(std::bitset<51> bits, int size) {
	if (size == sSize) {
		if (bits == sbits) return true;
		return false;
	}
	if (bits[size - 1]) {
		if (!bits[0]) return false;
		reverseBit(bits, size);
		bits[size - 1] = 0;
		return subAB(bits, size - 1);
	}
	else {
		bool result = subAB(bits, size - 1);
		if (result) return result;
		if (bits[0]) {
			reverseBit(bits, size);
			bits[size - 1] = 0;
			return subAB(bits, size - 1);
		}
	}
	return false;
}

int main() {
	std::string S;
	std::string T;
	std::cin >> S >> T;
	sSize = S.size();
	if (sSize < T.size()) {
		setBit(T, tbits);
		setBit(S, sbits);
		printf("%d\n", subAB(tbits, T.size()));
	}
	else if (S == T) printf("1\n");
	else printf("0\n");
}