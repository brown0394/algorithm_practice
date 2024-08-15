#include <iostream>
#include <vector>
std::vector<int> seq;
std::vector<std::vector<std::vector<int>>> dp;
int len;
const int INF = 1000000000;
const int score[5][5]{
	{1, 2, 2, 2, 2},
	{2, 1, 3, 4, 3},
	{2, 3, 1, 3, 4},
	{2, 4, 3, 1, 3},
	{2, 3, 4, 3, 1}
};

int findMinEnergyUse(int i, int leftf, int rightf) {
	if (i == len) return 0;
	if (dp[i][leftf][rightf] < 0) {
		int one = findMinEnergyUse(i + 1, seq[i], rightf) + score[leftf][seq[i]];
		int two = findMinEnergyUse(i + 1, leftf, seq[i]) + score[rightf][seq[i]];
		if (one < two) dp[i][leftf][rightf] = one;
		else dp[i][leftf][rightf] = two;
	}
	return dp[i][leftf][rightf];
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	while (true) {
		int in;
		std::cin >> in;
		if (!in) break;
		seq.push_back(in);
	}
	len = seq.size();
	dp.resize(len, std::vector<std::vector<int>>({
		{ -1, -1, -1, -1, -1 },
		{ -1, INF, -1, -1, -1 },
		{ -1, -1, INF, -1, -1 },
		{ -1, -1, -1, INF, -1 },
		{ -1, -1, -1, -1, INF } }));
	std::cout << findMinEnergyUse(0, 0, 0) << '\n';
}