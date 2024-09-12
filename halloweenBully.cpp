#include <iostream>
#include <vector>
#include <algorithm>

struct info {
	int candies;
	int leader;
	int groupSize;
};

struct group {
	int candies;
	int size;
	bool operator < (const group& other) {
		if (size == other.size) {
			return candies > other.candies;
		}
		return size < other.size;
	}
};

std::vector<info> candyGroups;

int getLeader(int cur) {
	if (candyGroups[cur].leader == cur) {
		return cur;
	}
	candyGroups[cur].leader = getLeader(candyGroups[cur].leader);
	return candyGroups[cur].leader;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int kids, friendRelations, cryBabies;
	std::cin >> kids >> friendRelations >> cryBabies;
	candyGroups.resize(kids + 1);
	for (int i = 1; i <= kids; ++i) {
		std::cin >> candyGroups[i].candies;
		candyGroups[i].leader = i;
		candyGroups[i].groupSize = 1;
	}
	
	for (int i = 0, one, two; i < friendRelations; ++i) {
		std::cin >> one >> two;
		int leader1 = getLeader(one);
		int leader2 = getLeader(two);
		if (leader1 == leader2) continue;
		if (leader1 > leader2) std::swap(leader1, leader2);
		candyGroups[leader1].candies += candyGroups[leader2].candies;
		candyGroups[leader1].groupSize += candyGroups[leader2].groupSize;
		candyGroups[leader2].leader = leader1;
	}
	std::vector<group> groups;
	groups.push_back({0, 0});
	for (int i = 1; i <= kids; ++i) {
		if (candyGroups[i].leader == i) {
			groups.push_back({ candyGroups[i].candies, candyGroups[i].groupSize });
		}
	}
	std::sort(groups.begin(), groups.end());
	std::vector<std::vector<int>> maxVals(cryBabies, std::vector<int>(groups.size()));
	for (int i = 0; i < cryBabies; ++i) {
		for (int j = 1, size = groups.size(); j < size; ++j) {
			maxVals[i][j] = maxVals[i][j - 1];
			if (i >= groups[j].size && maxVals[i][j] < maxVals[i - groups[j].size][j - 1] + groups[j].candies) {
				maxVals[i][j] = maxVals[i - groups[j].size][j - 1] + groups[j].candies;
			}
		}
	}
	std::cout << maxVals[cryBabies - 1][groups.size() - 1] << '\n';
}