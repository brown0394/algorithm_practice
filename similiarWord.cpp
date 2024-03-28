#include <iostream>
#include <cstring>

#define ALPHABETS 26

int main() {
	int words;
	char in;
	scanf_s("%d%c", &words, &in);
	int letters[ALPHABETS]{ 0 };
	int lettersComp[ALPHABETS]{ 0 };
	int lettersLen = 0;
	while (true) {
		scanf_s("%c", &in);
		if (in == '\n') break;
		++letters[in - 'A'];
		++lettersLen;
	}
	int similiar = 0;

	for (int i = 1; i < words; ++i) {
		int changes = 0;
		int compLen = 0;
		while (true) {
			scanf_s("%c", &in);
			if (in == '\n') {
				if (compLen < lettersLen) {
					if ((lettersLen - compLen) == 1 && changes < 2) ++similiar;
				}
				else if (changes < 2 && compLen == lettersLen) ++similiar;
				break;
			}
			in -= 'A';
			if (lettersComp[in] < letters[in]) {
				++lettersComp[in];
				++compLen;
			}
			else ++changes;
		}
		memset(lettersComp, 0, ALPHABETS * sizeof(int));
	}
	printf("%d\n", similiar);
}