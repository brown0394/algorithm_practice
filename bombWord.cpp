#include <iostream>
#include <string>
#include <vector>

class StringBomb {
private:
	std::string str;
	std::string bomb;
	int bombLen;
	int strLen;
public:
	StringBomb();
	void removeBomb();
};

StringBomb::StringBomb() {
	std::cin >> str >> bomb;
	bombLen = bomb.size() - 1;
	strLen = str.size();
}

void StringBomb::removeBomb() {
	int idx = 0;
	for (int i = 0; i < strLen; ++i) {
		if (str[i] == bomb[bombLen] && idx >= bombLen) {
			str[idx] = str[i];
			int j = 0;
			for (; j <= bombLen; ++j) {
				if (str[idx - j] != bomb[bombLen - j]) break;
			}
			if (j > bombLen) idx -= bombLen;
			else ++idx;
		}
		else {
			str[idx++] = str[i];
		}
	}
	if (idx) {
		for (int i = 0; i < idx; ++i) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
	else printf("FRULA\n");
}

int main() {
	StringBomb str;
	str.removeBomb();
}