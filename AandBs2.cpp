#include <iostream>
#include <string>
#include <bitset>

std::bitset<51> tbits;
int tsize;

void setBit(std::string& str, std::bitset<51>& bits) {
	for (int i = 0, size = str.size(); i < size; ++i) {
		if (str[i] == 'B') bits[i] = true;
	}
}
//visit rcord
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

bool addAB(std::bitset<51> bits, int size) {
	if (size == tsize) {
		if (bits == tbits) return true;
		return false;
	}
	bool result = addAB(bits, size + 1);
	bits[size] = true;
	reverseBit(bits, size + 1);
	return result || addAB(bits, size + 1);
}

int main() {
	std::string S;
	std::string T;
	std::cin >> S >> T;
	tsize = T.size();
	if (S.size() < tsize) {
		setBit(T, tbits);
		std::bitset<51> sbits;
		setBit(S, sbits);
		printf("%d\n", addAB(sbits, S.size()));
	}
	else if (S == T) printf("1\n");
	else printf("0\n");
	
}