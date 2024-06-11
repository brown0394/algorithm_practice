#include <iostream>
#include <vector>

const int win = 2;
const char jiu = 1;
const char kyung = 2;
const char min = 4;
int nItems, winN, allkind;
int jwins = 0, kwins = 0, mwins = 0, kidx = 0, midx = 0;
std::vector<std::vector<int>> wdl;
std::vector<std::vector<int>> kymin;
bool canWin(char nowPlaying, int used) {
	if (midx == 20 || kidx == 20) return false;
	if (!used) printf("\n-----------\n");
	printf("jw %d, kw %d, mw %d\n", jwins, kwins, mwins);
	char next = kyung;
	int cur = 1;
	int* curIdx = &midx;
	bool result = false;
	if (nowPlaying == 3) {
		next = min;
		cur = 0;
		curIdx = &kidx;
	}
	else if (nowPlaying == 6){
		int* wins;
		printf("k %d, m %d result : %d\n\n", kymin[0][kidx], kymin[1][midx], wdl[kymin[0][kidx]][kymin[1][midx]]);
		if (wdl[kymin[0][kidx]][kymin[1][midx]] == win) {
			next = kyung;
			wins = &kwins;
		}
		else {
			next = min;
			wins = &mwins;
		}
		if (*wins + 1 == winN) return false;
		++kidx;
		++midx;
		++(*wins);
		result = canWin(next | jiu, used);
		--(*wins);
		--kidx;
		--midx;
		printf("ret\n");
		return result;
	}
	int curItem = 1;
	for (int i = 1; i <= nItems; ++i) {
		if (!(used & curItem)) {
			char op;
			if (cur) op = 'm';
			else op = 'k';
			printf("j %d, %c %d result: %d\n\n", i, op, kymin[cur][*curIdx], wdl[i][kymin[cur][*curIdx]]);
			if (wdl[i][kymin[cur][*curIdx]] == win) {
				if (jwins + 1 == winN) {
					return true;
				}
				++jwins;
				++(*curIdx);
				result = canWin(next | jiu, used | curItem);
				--jwins;
				--(*curIdx);
				printf("ret\n");
			}
			else {
				int* wins;
				int winner;
				int* idx;
				if (cur) {
					winner = min;
					idx = &midx;
					wins = &mwins;
				}
				else {
					winner = kyung;
					idx = &kidx;
					wins = &kwins;
				}
				if (*wins + 1 < winN) {
					++(*wins);
					++(*idx);
					result = canWin(next | winner, used | curItem);
					--(*wins);
					--(*idx);
					printf("ret\n");
				}
			}
			if (result) return true;
		}
		curItem <<= 1;
	}
	return result;
}

int main() {
	scanf_s("%d %d", &nItems, &winN);
	wdl.resize(nItems + 1, std::vector<int>(nItems + 1));
	for (int i = 1; i <= nItems; ++i) {
		for (int j = 1; j <= nItems; ++j) scanf_s("%d", &wdl[i][j]);
	}
	kymin.resize(2, std::vector<int>(20));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 20; ++j) scanf_s("%d", &kymin[i][j]);
	}
	if (canWin(jiu | kyung, 0)) printf("1\n");
	else printf("0\n");
}