#include <iostream>
#include <string>
#include <bitset>
#include <set>

struct node {
	std::bitset<51> bits;
	int size;
};

struct bitInfo {
	long long bits;
	int size;
};

bool operator < (const bitInfo& one, const bitInfo& another) {
	if (one.bits == another.bits) return one.size < another.size;
	return one.bits < another.bits;
}

std::set<bitInfo> visitList;
std::bitset<51> tbits;
int tsize;

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

bool addAB(node info) {
	if (info.size == tsize) {
		if (info.bits == tbits) return true;
		return false;
	}
	bitInfo binfo{ info.bits.to_ullong(), info.size };
	auto found = visitList.find(binfo);
	if (found == visitList.end()) {
		visitList.insert(binfo);
		++info.size;
		bool result = addAB(info);
		info.bits[info.size - 1] = true;
		reverseBit(info.bits, info.size);
		return result || addAB(info);
	}
	return false;
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
		printf("%d\n", addAB(node{ sbits, static_cast<int>(S.size()) }));
	}
	else if (S == T) printf("1\n");
	else printf("0\n");

}