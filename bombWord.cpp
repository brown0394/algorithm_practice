#include <iostream>
#include <cstring>
#include <vector>

class StringBomb {
private:
	char str[1000001];
	char bomb[37];
	int bombLen;
	int strLen;
	int checkBomb(int i);
public:
	StringBomb();
	void removeBomb();
	void print();
};

StringBomb::StringBomb() {
	scanf_s("%s %s", &str, 1000001, &bomb, 37);
	bombLen = strlen(bomb);
	strLen = strlen(str);
}

int StringBomb::checkBomb(int i) {
	std::vector<int> trace;
	if (i + bombLen <= strLen) {
		for (int j = 0; j < bombLen; ++j) {
			if (str[i + j] != bomb[j]) {
				for (int k = 0; k < trace.size(); ++k) {
					str[trace[k]] = bomb[k];
				}
				return i;
			}
			trace.push_back(i + j);
			if (j && str[i + j] == bomb[0]) {
				int val = checkBomb(i + j);
				if (val != i + j) {
					if (str[i + j] == '-') {
						--j;
						trace.pop_back();
					}
					i = val - j;
				}
			}
			str[i + j] = '-';
		}
		return i + bombLen - 1;
	}
	return i;
}

void StringBomb::removeBomb() {
	for (int i = 0; i < strLen; ++i) {
		if (str[i] == bomb[0]) {
			int val = checkBomb(i);
			if (val == i) printf("%c", str[i]);
			else i = val;
		}
		else if (str[i] != '-') printf("%c", str[i]);
	}
}

int main() {
	StringBomb str;
	str.removeBomb();
}