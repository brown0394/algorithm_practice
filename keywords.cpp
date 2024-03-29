#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	std::unordered_set<std::string> keywords;
	int words, sentences;
	std::string in;
	std::cin >> words >> sentences;
	for (int i = 0; i < words; ++i) {
		std::cin >> in;
		keywords.insert(in);
	}
	std::string word;
	for (int i = 0; i < sentences; ++i) {
		std::cin >> in;
		int idx = 0;
		while (true) {
			if (in[idx] == ',' || in[idx] == '\0') {
				auto found = keywords.find(word);
				if (found != keywords.end()) keywords.erase(found);
				word.clear();
				if (in[idx] == '\0') break;
			}
			else word.push_back(in[idx]);
			++idx;
		}
		std::cout << keywords.size() << '\n';
	}
}