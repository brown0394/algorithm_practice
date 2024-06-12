#include <iostream>
#include <vector>
#include <cstring>
//https://www.acmicpc.net/problem/15898
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
const int spins = 4;
const int locs = 4;
node infos[3];
int maxQual = 0;

void clearPot() {
	memset(numPot, 0, intSize * 25);
	memset(colorPot, 'W', 25);
}

void apply(int idx) {
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
				numPot[r+j][c+k] += ingreds[i][j][k].val;
				if (ingreds[i][j][k].color != 'W') colorPot[r + j][c + k] = ingreds[i][j][k].color;
				if (numPot[r + j][c + k] < 0) numPot[r + j][c + k] = 0;
				else if (numPot[r + j][c + k] > 9) numPot[r + j][c + k] = 9;
			}
		}
		break;
	}
	case 1: {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				numPot[r + j][c + k] += ingreds[i][3 - k][j].val;
				if (ingreds[i][3 - k][j].color != 'W') colorPot[r + j][c + k] = ingreds[i][3 - k][j].color;
				if (numPot[r + j][c + k] < 0) numPot[r + j][c + k] = 0;
				else if (numPot[r + j][c + k] > 9) numPot[r + j][c + k] = 9;
			}
		}
		break;
	}
	case 2: {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				numPot[r + j][c + k] += ingreds[i][3-j][3-k].val;
				if (ingreds[i][3 - j][3 - k].color != 'W') colorPot[r + j][c + k] = ingreds[i][3 - j][3 - k].color;
				if (numPot[r + j][c + k] < 0) numPot[r + j][c + k] = 0;
				else if (numPot[r + j][c + k] > 9) numPot[r + j][c + k] = 9;
			}
		}
		break;
	}
	case 3: {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				numPot[r + j][c + k] += ingreds[i][k][3-j].val;
				if (ingreds[i][k][3 - j].color != 'W') colorPot[r + j][c + k] = ingreds[i][k][3 - j].color;
				if (numPot[r + j][c + k] < 0) numPot[r + j][c + k] = 0;
				else if (numPot[r + j][c + k] > 9) numPot[r + j][c + k] = 9;
			}
		}
		break;
	}
	}
}

void printPot() {
	printf("idxs %d %d %d\n", infos[0].idx, infos[1].idx, infos[2].idx);
	printf("spins %d %d %d\n", infos[0].spin, infos[1].spin, infos[2].spin);
	printf("locs %d %d %d\n", infos[0].loc, infos[1].loc, infos[2].loc);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			printf("%d%c ", numPot[i][j], colorPot[i][j]);
		}
		putchar('\n');
	}
}

int calcVal() {
	int R = 0, B = 0, G = 0, Y = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			switch (colorPot[i][j]) {
			case 'B': { B += numPot[i][j]; break; }
			case 'G': { G += numPot[i][j]; break; }
			case 'R': { R += numPot[i][j]; break; }
			case 'Y': { Y += numPot[i][j]; break; }
			}
		}
	}
	return (R * 7) + (B * 5) + (G * 3) + (Y * 2);
}

void setLocs() {
	for (int i = 0; i < locs; ++i) {
		infos[0].loc = i;
		for (int j = 0; j < locs; ++j) {
			infos[1].loc = j;
			for (int k = 0; k < locs; ++k) {
				infos[2].loc = k;
				clearPot();
				for (int l = 0; l < 3; ++l) apply(l);
				int result = calcVal();
				if (result > maxQual) maxQual = result;
			}
		}
	}
}

void setSpins() {
	int max = 0;
	for (int i = 0; i < spins; ++i) {
		infos[0].spin = i;
		for (int j = 0; j < spins; ++j) {
			infos[1].spin = j;
			for (int k = 0; k < spins; ++k) {
				infos[2].spin = k;
				setLocs();
			}
		}
	}
}

void calcQuality() {
	for (int i = 0; i < ingredients; ++i) {
		infos[0].idx = i;
		for (int j = 0; j < ingredients; ++j) {
			if (i == j) continue;
			infos[1].idx = j;
			for (int k = 0; k < ingredients; ++k) {
				if (i == k || j == k) continue;
				infos[2].idx = k;
				setSpins();
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
	calcQuality();
	printf("%d\n", maxQual);
}