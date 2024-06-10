#include <iostream>
#include <vector>

struct status {
	int idx, wins;
};

const int players = 3;
const char jiu = 2;
const char kyung = 0;
const char min = 1;
const int jidx = 0, win = 2;
int nItems, winN, allkind;
status curStatus[3] { 0 };
std::vector<std::vector<int>> wdl;
std::vector<std::vector<int>> itemUsed;
bool canWin(int used, int winner, int challenger) {
	if (!used) printf("\n-----------\n");
	printf("kw %d, mw %d, jw %d\n", curStatus[kyung].wins, curStatus[min].wins, curStatus[jiu].wins);
	bool result = false;
	if (winner < jiu && challenger < jiu) {
		printf("p1 = %d, %d | p2 = %d, %d | r %d\n", winner, itemUsed[winner][curStatus[winner].idx], challenger,
			itemUsed[challenger][curStatus[challenger].idx], wdl[itemUsed[winner][curStatus[winner].idx]][itemUsed[challenger][curStatus[challenger].idx]]);
		if (wdl[itemUsed[winner][curStatus[winner].idx]][itemUsed[challenger][curStatus[challenger].idx]] == win) {
			if (curStatus[winner].wins + 1 == winN) return false;
			++curStatus[winner].idx;
			++curStatus[challenger].idx;
			++curStatus[winner].wins;
			result = canWin(used, winner, jiu);
			--curStatus[winner].wins;
		}
		else {
			if (curStatus[challenger].wins + 1 == winN) return false;
			++curStatus[winner].idx;
			++curStatus[challenger].idx;
			++curStatus[challenger].wins;
			result = canWin(used, challenger, jiu);
			--curStatus[challenger].wins;
		}
		--curStatus[winner].idx;
		--curStatus[challenger].idx;
		return result;
	}
	bool jiuFirst = winner == jiu;
	for (int i = 1; i <= nItems; ++i) {
		curStatus[jiu].idx = i;
		printf("p1 = %d, %d | p2 = %d, %d | r %d\n", winner, itemUsed[winner][curStatus[winner].idx], challenger,
			itemUsed[challenger][curStatus[challenger].idx], wdl[itemUsed[winner][curStatus[winner].idx]][itemUsed[challenger][curStatus[challenger].idx]]);
		if (wdl[itemUsed[winner][curStatus[winner].idx]][itemUsed[challenger][curStatus[challenger].idx]] == win) {
			if (curStatus[winner].wins + 1 == winN) {
				if (jiuFirst && (used | (1 << (i-1))) == allkind) return true;
			}
			else {
				++curStatus[winner].wins;
				++curStatus[winner].idx;
				result = canWin(used | (1 << (i - 1)), winner, 3 - winner - challenger);
				--curStatus[winner].wins;
				--curStatus[winner].idx;
			}
		}
		else {
			if (curStatus[challenger].wins + 1 == winN) {
				if (!jiuFirst && (used | (1 << (i - 1))) == allkind) return true;
			}
			else {
				++curStatus[challenger].wins;
				++curStatus[challenger].idx;
				result = canWin(used | (1 << (i - 1)), challenger, 3 - winner - challenger);
				--curStatus[challenger].wins;
				--curStatus[challenger].idx;
			}
		}
		if (result) break;
	}
	return result;
}

int main() {
	scanf_s("%d %d", &nItems, &winN);
	int curItem = 1;
	for (int i = 0; i < nItems; ++i) {
		allkind |= curItem;
		curItem <<= 1;
	}
	wdl.resize(nItems + 1, std::vector<int>(nItems + 1));
	for (int i = 1; i <= nItems; ++i) {
		for (int j = 1; j <= nItems; ++j) scanf_s("%d", &wdl[i][j]);
	}
	itemUsed.resize(2, std::vector<int>(20));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 20; ++j) scanf_s("%d", &itemUsed[i][j]);
	}
	itemUsed.push_back(std::vector<int>(nItems+1));
	for (int i = 0; i <= nItems; ++i) {
		itemUsed[jiu][i] = i;
	}
	if (canWin(0, 2, 0)) printf("1\n");
	else printf("0\n");
}