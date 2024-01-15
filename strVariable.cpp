#include <iostream>

#define LEN 101

void camelCase(char* str) {
	char snakeStr[111];
	char pascalStr[111];
	pascalStr[0] = str[0] - 32;
	snakeStr[0] = str[0];
	int snakeIdx = 1;
	int i = 1;
	for (; str[i] != '\0'; ++i) {
		if (str[i] <= 90) {
			snakeStr[snakeIdx++] = '_';
			snakeStr[snakeIdx++] = str[i] + 32;
		}
		else snakeStr[snakeIdx++] = str[i];
		pascalStr[i] = str[i];
	}
	snakeStr[snakeIdx] = '\0';
	pascalStr[i] = '\0';
	printf("%s\n%s\n%s\n", str, snakeStr, pascalStr);
}

void snakeCase(char* str) {
	char camelStr[101];
	char pascalStr[101];
	pascalStr[0] = str[0] - 32;
	camelStr[0] = str[0];
	int idx = 1;
	bool underBar = false;
	for (int i = 1; str[i] != '\0'; ++i) {
		if (str[i] == '_') {
			underBar = true;
		}
		else {
			camelStr[idx] = str[i];
			pascalStr[idx] = str[i];
			if (underBar) {
				underBar = false;
				camelStr[idx] -= 32;
				pascalStr[idx] -= 32;
			}
			++idx;
		}
	}
	camelStr[idx] = '\0';
	pascalStr[idx] = '\0';
	printf("%s\n%s\n%s\n", camelStr, str, pascalStr);
}

void pascalCase(char* str) {
	char snakeStr[111];
	char camelStr[111];
	camelStr[0] = str[0] + 32;
	snakeStr[0] = camelStr[0];
	int snakeIdx = 1;
	int i = 1;
	for (; str[i] != '\0'; ++i) {
		if (str[i] <= 90) {
			snakeStr[snakeIdx++] = '_';
			snakeStr[snakeIdx++] = str[i] + 32;
		}
		else snakeStr[snakeIdx++] = str[i];
		camelStr[i] = str[i];
	}
	snakeStr[snakeIdx] = '\0';
	camelStr[i] = '\0';
	printf("%s\n%s\n%s\n", camelStr, snakeStr, str);
}

int main() {
	int n;
	char str[LEN];
	scanf_s("%d %s", &n, str, LEN);
	switch (n) {
	case 1: { camelCase(str); break; }
	case 2: { snakeCase(str); break; }
	case 3: { pascalCase(str); break; }
	}
}
