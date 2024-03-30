#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

struct node {
	int level;
	std::string nickName;
	node(int p_level, std::string&& str) : level(p_level), nickName(str) {}
	bool operator < (const node& other) {
		return nickName < other.nickName;
	}
};

int main() {
	int players, capacity;
	scanf_s("%d %d", &players, &capacity);

	std::list<std::vector<node>> gameGroups;
	int inLevel;
	std::string inNickName;
	for (int i = 0; i < players; ++i) {
		std::cin >> inLevel >> inNickName;
		if (!gameGroups.empty()) {
			auto it = gameGroups.begin();
			bool added = false;
			while (it != gameGroups.end()) {
				if (it->size() < capacity && (((*it)[0].level > inLevel && ((*it)[0].level - inLevel <= 10)) ||
					((*it)[0].level <= inLevel && (inLevel - (*it)[0].level <= 10)))) {
					it->emplace_back(node(inLevel, std::move(inNickName)));
					added = true;
					break;
				}
				else ++it;
			}
			if (!added) goto newgroup;
		}
		else {
			newgroup:
			gameGroups.emplace_back(std::vector<node>());
			gameGroups.back().reserve(capacity);
			gameGroups.back().emplace_back(node(inLevel, std::move(inNickName)));
		}
	}
	for (auto it = gameGroups.begin(); it != gameGroups.end(); ++it) {
		if (it->size() < capacity) printf("Waiting!\n");
		else printf("Started!\n");
		std::sort(it->begin(), it->end());
		for (auto names = it->begin(); names != it->end(); ++names) {
			std::cout << names->level << ' ' << names->nickName << '\n';
		}
	}
}