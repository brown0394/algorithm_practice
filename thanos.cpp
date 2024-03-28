#include <iostream>
#include <string>

int main() {
	std::string str;
	std::cin >> str;
	int ones = 0, zeros = 0;
	int len = str.size();
	for (int i = 0; i < len; ++i) {
		if (str[i] == '0') ++zeros;
		else ++ones;
	}
	ones >>= 1;
	zeros >>= 1;
	for (int i = 0; i < len; ++i) {
		if (str[i] == '1') {
			str[i] = '-';
			if (ones-- == 1) break;
		}
	}
	for (int i = len-1; i >= 0; --i) {
		if (str[i] == '0') {
			str[i] = '-';
			if (zeros-- == 1) break;
		}
	}
	for (int i = 0; i < len; ++i) {
		if (str[i] != '-')printf("%c", str[i]);
	}
	printf("\n");
}