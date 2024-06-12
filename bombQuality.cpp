#include <iostream>
#include <vector>
#include <cstring>

struct ingredInfo {
	int val;
	char color;
};

struct node {
	int idx;
	int spin;
	int loc;
};

int numPot[5][5];
char colorPot[5][5];
int ingredients;
std::vector<std::vector<std::vector<ingredInfo>>> ingreds;
const int intSize = sizeof(int);
const int spins = 3;
const int locs = 4;
node infos[3];

void clearPot() {
	memset(numPot, 0, intSize * 25);
	memset(colorPot, 'w', 25);
}

int apply(int idx) {
	int r = 0, c = 0;
	switch (infos[idx].loc) {
	case 1: { ++c; break; }
	case 2: { ++r; break; }
	case 3: { ++c; ++r; break; }
	}
	int i = infos[idx].idx;
	switch (infos[idx].spin) {
	case 0: {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (numPot[r+j][c+k] + ingreds[i][j][k].val < 0) numPot[r+j][c+k] = 0;
				else numPot[r+j][c+k] += ingreds[i][j][k].val;
				colorPot[r+j][c+k] = ingreds[i][j][k].color;
			}
		}
		break;
	}
	case 1: {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (numPot[r + j][c + k] + ingreds[i][3 - k][j].val < 0) numPot[r + j][c + k] = 0;
				else numPot[r + j][c + k] += ingreds[i][3 - k][j].val;
				colorPot[r + j][c + k] = ingreds[i][3 - k][j].color;
			}
		}
		break;
	}
	case 2: { ++r; break; }
	case 3: { ++c; ++r; break; }
	}
}

int setLocs() {
	for (int i = 0; i < locs; ++i) {
		infos[0].loc = i;
		for (int j = 0; j < locs; ++j) {
			infos[1].loc = j;
			for (int k = 0; k < locs; ++k) {
				infos[2].loc = k;
			}
		}
	}
}

int setSpins() {
	for (int i = 0; i < spins; ++i) {
		infos[0].spin = i;
		for (int j = 0; j < spins; ++j) {
			infos[1].spin = j;
			for (int k = 0; k < spins; ++k) {
				infos[2].spin = k;
			}
		}
	}
}

int calcQuality() {
	for (int i = 0; i < ingredients; ++i) {
		infos[0].idx = i;
		for (int j = 0; j < ingredients; ++j) {
			if (i == j) continue;
			infos[1].idx = j;
			for (int k = 0; k < ingredients; ++k) {
				if (i == k || j == k) continue;
				infos[2].idx = k;
			}
		}
	}

}

int main() {
	scanf_s("%d", &ingredients);
	ingreds.resize(ingredients, std::vector<std::vector<ingredInfo>>(4, std::vector<ingredInfo>(4)));
	for (int i = 0; i < ingredients; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				scanf_s("%d", &ingreds[i][j][k].val);
			}
		}
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				getchar();
				ingreds[i][j][k].color = getchar();
			}
		}
	}

}