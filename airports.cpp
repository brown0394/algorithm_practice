#include <iostream>
#include <set>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::set<int> gates;
	int numOfGates, numOfFlights;
	std::cin >> numOfGates >> numOfFlights;
	for (int i = 1; i <= numOfGates; ++i) gates.emplace_hint(gates.end(), i);
	bool fullGates = false;
	for (int i = 0, range; i < numOfFlights; ++i) {
		std::cin >> range;
		if (fullGates) continue;
		auto found = gates.lower_bound(range);
		if (found != gates.end() && *found <= range) {
			gates.erase(found);
		}
		else if (found == gates.begin()) {
			std::cout << i << '\n';
			fullGates = true;
		}
		else {
			gates.erase(--found);
		}
	}
	if (!fullGates) std::cout << numOfFlights << '\n';
}