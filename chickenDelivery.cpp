#include <iostream>
#include <vector>

struct coord {
	int row;
	int col;
};

class chickenNavigator {
	std::vector<coord> houses;
	std::vector<coord> chickenPlaces;
	std::vector<int> choices;
	int m;
	int chickenLen;
public:
	chickenNavigator(int p_n, int p_m);
	int rearrangeChoice(int idx);
	int getMaxDist();
};

chickenNavigator::chickenNavigator(int p_n, int p_m) : m(p_m), choices(p_m) {
	int in;
	for (int i = 1; i <= p_n; ++i) {
		for (int j = 1; j <= p_n; ++j) {
			scanf_s("%d", &in);
			if (in == 1) {
				houses.push_back({ i, j });
			}
			else if (in == 2) {
				chickenPlaces.push_back({ i, j });
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		choices[i] = i;
	}
	chickenLen = chickenPlaces.size();
}

int chickenNavigator::getMaxDist() {
	int distR, distC;
	const int MAX = ~(1 << 31);
	int maxVal = MAX;
	int sum, tempsum;

	while (true) {
		sum = 0;
		for (auto home = houses.begin(); home != houses.end(); ++home) {
			tempsum = MAX;
			for (int i = 0; i < m; ++i) {
				distR = chickenPlaces[choices[i]].row - home->row;
				distC = chickenPlaces[choices[i]].col - home->col;
				if (distR < 0) distR *= -1;
				if (distC < 0) distC *= -1;
				distR += distC;
				if (tempsum > distR) {
					tempsum = distR;
				}
			}
			sum += tempsum;
			if (sum > maxVal) break;
		}
		if (sum < maxVal) maxVal = sum;
		if (choices[0] == chickenLen - m) break;
		if (choices[m - 1] + 1 < chickenLen) {
			++choices[m - 1];
		}
		else {
			choices[m - 1] = rearrangeChoice(m - 2) + 1;
		}
	}
	return maxVal;
}
int chickenNavigator::rearrangeChoice(int idx) {
	if (choices[idx] + 1 < choices[idx + 1]) ++choices[idx];
	else choices[idx] = rearrangeChoice(idx - 1) + 1;
	return choices[idx];
}

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);
	chickenNavigator nav(n, m);
	printf("%d\n", nav.getMaxDist());
}