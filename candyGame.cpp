#include <iostream>

char str[51][51];
int n;

int check(int i, int j) {
	int max = 1;
	int combo = 1;
	for (int k = i + 1; k < n; ++k) {
		if (str[i][j] == str[k][j]) ++combo;
		else break;
	}
	for (int k = i - 1; k >= 0; --k) {
		if (str[i][j] == str[k][j]) ++combo;
		else break;
	}
	if (max < combo) max = combo;
	combo = 1;
	for (int k = j + 1; k < n; ++k) {
		if (str[i][j] == str[i][k]) ++combo;
		else break;
	}
	for (int k = j - 1; k >= 0; --k) {
		if (str[i][j] == str[i][k]) ++combo;
		else break;
	}
	if (max < combo) max = combo;
	return max;
}
void swap(char* one, char* two) {
	char temp = *one;
	*one = *two;
	*two = temp;
}
int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i) {
		getchar();
		scanf_s("%s", &str[i][0], 51);
	}
	int maxCombo = 0;
	int combo;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			combo = 1;
			if (i) {
				swap(&str[i][j], &str[i - 1][j]);
				combo = check(i, j);
				swap(&str[i][j], &str[i - 1][j]);
				if (combo > maxCombo) maxCombo = combo;
				combo = 1;
			}
			if (i + 1 < n) {
				swap(&str[i][j], &str[i + 1][j]);
				combo = check(i, j);
				swap(&str[i][j], &str[i + 1][j]);
				if (combo > maxCombo) maxCombo = combo;
				combo = 1;
			}
			if (j) {
				swap(&str[i][j], &str[i][j - 1]);
				combo = check(i, j);
				swap(&str[i][j], &str[i][j - 1]);
				if (combo > maxCombo) maxCombo = combo;
				combo = 1;
			}
			if (j + 1 < n) {
				swap(&str[i][j], &str[i][j + 1]);
				combo = check(i, j);
				swap(&str[i][j], &str[i][j + 1]);
				if (combo > maxCombo) maxCombo = combo;
			}
		}
	}
	printf("%d\n", maxCombo);
}
