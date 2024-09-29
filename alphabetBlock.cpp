#include <iostream>
#include <list>
#include <algorithm>
#include <stack>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::list<char> str;
	int commands;
	const int FRONT = 2;
	const int BACK = 1;
	std::stack<int> recentInsert;
	std::cin >> commands;
	for (int i = 0, command; i < commands; ++i) {
		std::cin >> command;
		if (command == 3) {
			if (str.empty()) continue;
			if (recentInsert.top() == FRONT) str.pop_front();
			else str.pop_back();
			recentInsert.pop();
			continue;
		}
		char c;
		std::cin >> c;
		if (command == 1) str.push_back(c);
		else str.push_front(c);
		recentInsert.push(command);
	}
	if (str.empty()) std::cout << "0";
	else std::for_each(str.begin(), str.end(), [](char c) { std::cout << c; });
	std::cout << '\n';
}
