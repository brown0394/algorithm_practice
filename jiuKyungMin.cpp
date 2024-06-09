#include <iostream>
#include <vector>

const int players = 3;
const char jiu = 1;
const char kyung = 2;
const char min = 4;
int nItems, winN, til;
int jwins = 0, kwins = 0, mwins = 0, kidx = 0, midx = 0;
std::vector<std::vector<int>> wdl;
std::vector<std::vector<int>> kymin;
bool canWin(char nowPlaying, int used, int item) {
	char next;
	int cur = 1;
	bool result = false;
	if (nowPlaying == 3) {
		next = min;
		cur = 0;
	}
	else if (nowPlaying == 5) next = kyung;
	else {
		next = jiu;
		++kidx;
		++midx;
		if (!wdl[kymin[0][kidx]][kymin[1][midx]]) {
			if (mwins + 1 == winN) return false;
			++mwins;
			result = canWin(next | min, used, item);
			--mwins;
		}
		else {
			if (kwins + 1 == winN) return false;
			++kwins;
			result = canWin(next | kyung, used, item);
			--kwins;
		}
		--kidx;
		--midx;
		return result;
	}
	int curItem = 1;
	while (curItem < til) {
		if (!(used & curItem)) {
			if (!wdl[item][kymin[cur][]])
		}
	}
}

int main() {
	scanf_s("%d %d", &nItems, &winN);
	til = 1 << nItems;
	wdl.resize(players, std::vector<int>(nItems));
	for (int i = 0; i < players; ++i) {
		for (int j = 0; j < nItems; ++j) scanf_s("%d", &wdl[i][j]);
	}
	kymin.resize(2, std::vector<int>(20));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 20; ++j) scanf_s("%d", &kymin[i][j]);
	}
}