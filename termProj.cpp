#include <iostream>
#include <vector>
#include <cstring>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	int testCases;
	std::cin >> testCases;
	int students[100005];
	int chosenFrom[100005];
	for (int i = 0; i < testCases; ++i) {
		int numOfStudents;
		std::cin >> numOfStudents;
		int withoutTeam = 0;
		std::memset(chosenFrom, 0, sizeof(int) * (numOfStudents + 1));
		for (int i = 1; i <= numOfStudents; ++i) {
			std::cin >> students[i];
			++chosenFrom[students[i]];
		}
		for (int i = 1; i <= numOfStudents; ++i) {
			if (chosenFrom[i] == 0) {
				++withoutTeam;
				--chosenFrom[i];
				int cur = students[i];
				while (--chosenFrom[cur] == 0) {
					++withoutTeam;
					--chosenFrom[cur];
					cur = students[cur];
				}
			}
		}
		std::cout << withoutTeam << '\n';
	}
}