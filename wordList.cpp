#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

struct wordInfo {
	const std::string* str;
	int count;
	bool operator < (const wordInfo& other) {
		if (count == other.count) {
			if (str->size() == other.str->size()) {
				return *str < *other.str;
			}
			return str->size() > other.str->size();
		}
		return count > other.count;
	}
};

int main() {
	int words, minLen;
	scanf_s("%d %d", &words, &minLen);
	std::string in;
	std::map<std::string, int> idxMap;
	std::vector<wordInfo> wordOrder;
	int idx = 0;
	for (int i = 0; i < words; ++i) {
		std::cin >> in;
		if (in.size() >= minLen) {
			auto found = idxMap.find(in);
			if (found == idxMap.end()) {
				auto newOne = idxMap.insert({ in, idx++ });
				wordOrder.push_back(wordInfo{ &newOne.first->first, 1 });
			}
			else {
				++wordOrder[found->second].count;
			}
		}
	}
	std::sort(wordOrder.begin(), wordOrder.end());
	for (auto it = wordOrder.begin(); it != wordOrder.end(); ++it) {
		printf("%s\n", it->str->c_str());
	}
}
