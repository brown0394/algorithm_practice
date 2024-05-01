#include <iostream>
#include <vector>

int main() {
	char str[10];
	while (true) {
		scanf_s("%s", str, 10);
		if (str[0] == 'e') break;
		int x = 0, o = 0;
		for (int i = 0; i < 9; ++i) {
			switch (str[i]) {
			case 'X': { ++x; break; }
			case 'O': { ++o; break; }
			}
		}
		if (o <= x && (x - o) < 2 && x > 2) {
			int xstreak = 0;
			int ostreak = 0;
			for (int i = 0; i < 3; ++i) {
				if (str[i] == str[i + 3] && str[i + 3] == str[i + 6]) {
					if (str[i] == 'O') ++ostreak;
					else if (str[i] == 'X') ++xstreak;
				}
				int idx = i * 3;
				if (str[idx] == str[idx + 1] && str[idx + 1] == str[idx + 2]) {
					if (str[idx] == 'O') ++ostreak;
					else if (str[idx] == 'X') ++xstreak;
				}
			}
			if (str[0] == str[4] && str[4] == str[8]) {
				if (str[0] == 'O') ++ostreak;
				else if (str[0] == 'X') ++xstreak;
			}
			if (str[2] == str[4] && str[4] == str[6]) {
				if (str[2] == 'O') ++ostreak;
				else if (str[2] == 'X') ++xstreak;
			}
			if (xstreak) {
				if (ostreak || x == o) printf("invalid\n");
				else printf("valid\n");
			}
			else if (ostreak) {
				if (x > o) printf("invalid\n");
				else printf("valid\n");
			}
			else if (x + o == 9) {
				printf("valid\n");
			}
			else printf("invalid\n");
		}
		else printf("invalid\n");
	}
}