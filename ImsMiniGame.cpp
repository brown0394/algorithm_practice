#include <iostream>
#include <string>
#include <set>

int main() {
	int applications;
	char game;
	std::cin >> applications >> game;
	std::string applicant;
	std::set<std::string> candidates;
	for (int i = 0; i < applications; ++i) {
		std::cin >> applicant;
		candidates.insert(applicant);
	}
	switch (game) {
	case 'Y': { printf("%d\n", candidates.size()); break; }
	case 'F' : { printf("%d\n", candidates.size() >> 1); break; }
	case 'O' : { printf("%d\n", candidates.size() / 3); break; }
	}
}
