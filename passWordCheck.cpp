#include <iostream>


int main() {
	char str[25];
	char last;
	int vowel = 1065233;
	while (true) {
		scanf_s("%s", str, 25);
		if (str[3] == 0 && str[0] == 'e' && str[1] == 'n' && str[2] == 'd') break;
		last = 0;
		int vowelCount = 0;
		int consoCount = 0;
		bool valid = true;
		bool aeiou = false;
		for (int i = 0; str[i] != 0; ++i) {
			if (last == str[i] && last != 'o' && last != 'e') {
				valid = false;
				break;
			}
			int cur = 1 << (str[i] - 'a');
			if (vowel & cur) {
				aeiou = true;
				consoCount = 0;
				++vowelCount;
				if (vowelCount == 3) {
					valid = false;
					break;
				}
			}
			else {
				vowelCount = 0;
				++consoCount;
				if (consoCount == 3) {
					valid = false;
					break;
				}
			}
			last = str[i];
		}
		if (valid && aeiou) printf("<%s> is acceptable.\n", str);
		else printf("<%s> is not acceptable.\n", str);
	}

}
