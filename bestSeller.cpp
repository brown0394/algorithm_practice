#include <iostream>
#include <map>
#include <string>

int compareStr(const std::string& one, const std::string& two) {
	if (one.size() == two.size()) {
		for (int i = 0; i < one.size(); ++i) {
			if (one[i] < two[i]) return -1;
			else if (one[i] > two[i]) return 1;
		}
		return 0;
	}
	else {
		int len;
		int retVal;
		if (one.size() < two.size()) {
			len = one.size();
			retVal = -1;
		}
		else {
			len = two.size();
			retVal = 1;
		}
		for (int i = 0; i < len;++i) {
			if (one[i] < two[i]) return -1;
			else if (one[i] > two[i]) return 1;
		}
		return retVal;
	}
	return 0;
}

int main() {
	int n;
	scanf_s("%d", &n);
	std::map<std::string, int> bookBoard;
	std::string in;
	std::cin >> in;
	bookBoard.insert({ in, 1 });
	const std::string* best = &bookBoard.begin()->first;
	int max = 1;
	for (int i = 1; i < n; ++i) {
		std::cin >> in;
		auto found = bookBoard.find(in);
		if (found != bookBoard.end()) {
			++found->second;
			if (found->second > max) {
				max = found->second;
				best = &found->first;
			}
			else if (found->second == max && compareStr(*best, found->first) == 1) {
				best = &found->first;
			}
		}
		else {
			auto added = bookBoard.insert({ in, 1 });
			if (max == 1 && compareStr(*best, added.first->first) == 1) best = &added.first->first;
		}
	}
	std::cout << *best << '\n';
}
