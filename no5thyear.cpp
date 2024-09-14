#include <iostream>
#include <vector>


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	const int majorRequired = 66;
	const int totalRequired = 130;
	const int standardSem = 8;
	int semesterDone, majorCredit, totCredit;
	std::cin >> semesterDone >> majorCredit >> totCredit;
	for (int i = 1, major, general; i <= 10; ++i) {
		std::cin >> major >> general;
		if (semesterDone + i > standardSem) continue;
		int credits = 6;
		if (major <= 6) {
			credits -= major;
			int creditEarned = 3 * major;
			majorCredit += creditEarned;
			if (general >= credits) totCredit += creditEarned + credits * 3;
			else totCredit += creditEarned + general * 3;
		}
		else {
			majorCredit += 3 * 6;
			totCredit += 3 * 6;
		}
	}
	if (totCredit >= totalRequired && majorCredit >= majorRequired) {
		std::cout << "Nice\n";
	}
	else std::cout << "Nae ga wae\n";
}