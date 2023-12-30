#include <iostream>
#include <string>
#include <vector>

class StringBomb {
private:
	std::string str;
	std::string bomb;
	int bombLen;
	int strLen;
	int checkBomb(int i);
public:
	StringBomb();
	void removeBomb();
	void print();
};

StringBomb::StringBomb() {
	std::cin >> str >> bomb;
	bombLen = bomb.size();
	strLen = str.size();
}

int StringBomb::checkBomb(int i) {
	int init = i;
	std::vector<int> trace;
	if (i + bombLen <= strLen) {
		for (int j = 0; j < bombLen; ++j) {
			if (str[i + j] == '-') {
				++i;
				--j;
				continue;
			}
			if (j && str[i + j] == bomb[0]) {
				int val = checkBomb(i + j);
				if (val != i + j) {
					--j;
					i = val - j;
					continue;
				}
			}
			if (str[i + j] != bomb[j]) {
				for (int k = 0; k < trace.size(); ++k) {
					str[trace[k]] = bomb[k];
				}
				return init;
			}
			trace.push_back(i + j);
			str[i + j] = '-';
		}
		return i + bombLen - 1;
	}
	return i;
}

void StringBomb::removeBomb() {
	bool frula = true;
	for (int i = 0; i < strLen; ++i) {
		if (str[i] == bomb[0]) {
			int val = checkBomb(i);
			if (val == i) {
				printf("%c", str[i]);
				frula = false;
			}
			else i = val;
		}
		else if (str[i] != '-') {
			printf("%c", str[i]);
			frula = false;
		}
	}
	if (frula) printf("FRULA\n");
}

int main() {
	StringBomb str;
	str.removeBomb();
}