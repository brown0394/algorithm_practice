#include <iostream>
#include <vector>

int getRcsResult(char mine, char opponent) {
	if (opponent == mine) return 1;
	if (mine == 'R' && opponent == 'S') return 2;
	if (mine == 'S' && opponent == 'P') return 2;
	if (mine == 'P' && opponent == 'R') return 2;
	return 0;
}

enum RSP {
	P = 0,
	FREQ,
	R,
	S,
	FREQS
};

int main() {
	int round;
	scanf_s("%d", &round);
	char* mine = new char[round + 1];
	scanf_s("%s", mine, round + 1);
	int friends;
	scanf_s("%d", &friends);
	char** rcsFriends = new char* [friends];
	int score = 0;
	int bestScorePossible = 0;
	std::vector<std::vector<int>> gameRec(5, std::vector<int>(round));
	for (int i = 0; i < round; ++i) {
		gameRec[FREQ][i] = -1;
	}
	for (int i = 0; i < friends; ++i) {
		rcsFriends[i] = new char[round];
		getchar();
		for (int j = 0; j < round; ++j) {
			scanf_s("%c", &rcsFriends[i][j], 1);
			score += getRcsResult(mine[j], rcsFriends[i][j]);
			rcsFriends[i][j] -= 80;
			if (gameRec[FREQ][j] < 0) {
				gameRec[FREQ][j] = rcsFriends[i][j];
			}
			++gameRec[rcsFriends[i][j]][j];
			if (gameRec[FREQ][j] == rcsFriends[i][j]) {
				gameRec[FREQS][j] = 0;
				continue;
			}
			if (gameRec[gameRec[FREQ][j]][j] < gameRec[rcsFriends[i][j]][j]) {
				gameRec[FREQ][j] = rcsFriends[i][j];
				gameRec[FREQS][j] = 0;
			}
			else if (gameRec[gameRec[FREQ][j]][j] == gameRec[rcsFriends[i][j]][j]) {
				++gameRec[FREQS][j];
			}
		}
	}
	char seq[]{ 'P', 'F', 'R', 'S', 'Q' };
	for (int i = 0; i < 5; ++i) {
		printf("%c : ", seq[i]);
		for (int j = 0; j < round; ++j) {
			printf("%d ", gameRec[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < round; ++i) {
		if (!gameRec[FREQS][i]) {
			int winFreq = (gameRec[gameRec[FREQ][i]][i] << 1);
			int drawFreq = gameRec[gameRec[FREQ][i]][i];
			if (gameRec[FREQ][i] == P) {
				winFreq += gameRec[S][i];
				drawFreq += (gameRec[R][i] * 2);
			}
			else if (gameRec[FREQ][i] == R) {
				winFreq += gameRec[P][i];
				drawFreq += (gameRec[S][i] * 2);
			}
			else {
				winFreq += gameRec[R][i];
				drawFreq += (gameRec[P][i] * 2);
			}
			if (winFreq > drawFreq) bestScorePossible += winFreq;
			else bestScorePossible += drawFreq;
		}
		else if (gameRec[FREQS][i] == 1) {
			if (gameRec[P][i] == gameRec[R][i]) {
				bestScorePossible += (gameRec[R][i] << 1) + gameRec[P][i];
			}
			else if (gameRec[P][i] == gameRec[S][i]) {
				bestScorePossible += (gameRec[P][i] << 1) + gameRec[S][i];
			}
			else {
				bestScorePossible += (gameRec[S][i] << 1) + gameRec[R][i];
			}
		}
		else {
			bestScorePossible += gameRec[R][i] + (gameRec[R][i] << 1);
		}
	}

	printf("%d\n%d\n", score, bestScorePossible);

	delete[] mine;
	for (int i = 0; i < friends; ++i) {
		delete[] rcsFriends[i];
	}
	delete[] rcsFriends;
}
