#include <iostream>

int main() {
	char str[51][51];
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i) {
		getchar();
		scanf_s("%s", &str[i][0], 51);
	}
	int maxCombo = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int combo = 1;
			bool hasMoved = false;
			for (int k = i + 1; k < n; ++k) {
				if (str[i][j] == str[k][j]) ++combo;
				else if (!hasMoved) {
					if (j + 1 < n && str[i][j] == str[k][j + 1]) ++combo;
					else if (j && str[i][j] == str[k][j - 1]) ++combo;
					else if (k + 1 < n && str[i][j] == str[k + 1][j]) {
						++combo;
						if (maxCombo < combo) maxCombo = combo;
						combo = 1;
					}
					else break;
					hasMoved = true;
				}
				else break;
			}
			if (!hasMoved) {
				if (i && j + 1 < n && str[i][j] == str[i - 1][j + 1]) ++combo;
				else if (i && j && str[i][j] == str[i - 1][j - 1]) ++combo;
				else --combo;
			}
			if (maxCombo < combo) maxCombo = combo;
			combo = 1;
			hasMoved = false;
			for (int k = j + 1; k < n; ++k) {
				if (str[i][j] == str[i][k]) ++combo;
				else if (!hasMoved) {
					if (i + 1 < n && str[i][j] == str[i + 1][k]) ++combo;
					else if (i && str[i][j] == str[i - 1][k]) ++combo;
					else if (k + 1 < n && str[i][j] == str[i][k + 1]) {
						++combo;
						if (maxCombo < combo) maxCombo = combo;
						combo = 1;
					}
					else break;
					hasMoved = true;
				}
				else break;
			}
			if (!hasMoved) {
				if (j && i + 1 < n && str[i][j] == str[i + 1][j - 1]) ++combo;
				else if (j && i && str[i][j] == str[i - 1][j - 1]) ++combo;
				else --combo;
			}
			if (maxCombo < combo) maxCombo = combo;
		}
	}
	printf("%d\n", maxCombo);
}
