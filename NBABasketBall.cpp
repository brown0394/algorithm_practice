#include <iostream>

struct winingTime {
	int min, sec;
};
void addWiningTime(winingTime& team, winingTime& last, winingTime& cur) {
	team.min += (cur.min - last.min);
	if (cur.sec > last.sec) team.sec += (cur.sec - last.sec);
	else {
		--team.min;
		team.sec += (cur.sec + 60 - last.sec);
	}
	if (team.sec >= 60) {
		++team.min;
		team.sec -= 60;
	}
}

int main() {
	int goals;
	scanf_s("%d", &goals);
	winingTime team1{ 0 };
	winingTime team2{ 0 };
	winingTime lastTime1{ 0 };
	winingTime lastTime2{ 0 };
	int lastWinner = 0;
	int score1 = 0, score2 = 0;


	for (int i = 0; i < goals; ++i) {
		int team;
		winingTime cur;
		char temp1, temp2;
		scanf_s("%d", &team);
		getchar();
		scanf_s("%c%c", &temp1, 1, &temp2, 1);
		cur.min = ((temp1 - '0') * 10) + temp2 - '0';
		getchar();
		scanf_s("%c%c", &temp1, 1, &temp2, 1);
		cur.sec = ((temp1 - '0') * 10) + temp2 - '0';
		if (team == 1) {
			++score1;
			if (score1 > score2 && team != lastWinner) {
				if (lastWinner) {
					addWiningTime(team2, lastTime2, cur);
				}
				lastTime1.min = cur.min;
				lastTime1.sec = cur.sec;
				lastWinner = 1;
			}
			else if (score1 == score2) {
				if (lastWinner) {
					addWiningTime(team2, lastTime2, cur);
				}
				lastWinner = 0;
			}
		}
		else {
			++score2;
			if (team != lastWinner && score2 > score1) {
				if (lastWinner) {
					addWiningTime(team1, lastTime1, cur);
				}
				lastTime2.min = cur.min;
				lastTime2.sec = cur.sec;
				lastWinner = 2;
			}
			else if (score2 == score1) {
				if (lastWinner) {
					addWiningTime(team1, lastTime1, cur);
				}
				lastWinner = 0;
			}
		}
	}
	winingTime cur{ 48, 0 };
	if (lastWinner == 1 && score1 > score2) {
		addWiningTime(team1, lastTime1, cur);
	}
	else if (lastWinner == 2 && score1 < score2) {
		addWiningTime(team2, lastTime2, cur);
	}
	printf("%d%d:%d%d\n", team1.min / 10, team1.min % 10, team1.sec / 10, team1.sec % 10);
	printf("%d%d:%d%d\n", team2.min / 10, team2.min % 10, team2.sec / 10, team2.sec % 10);
}