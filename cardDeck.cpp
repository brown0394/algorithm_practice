#include <iostream>
#include <map>
#include <algorithm>

bool compare(std::pair<long long, int> one, std::pair<long long, int> two) {
	if (one.second == two.second) return two.first < one.first;
	return one.second < two.second;
}

int main() {
	int cards;
	std::map<long long, int> cardDeck;
	scanf("%d", &cards);
	long long input;
	for (int i = 0; i < cards; ++i) {
		scanf("%lld", &input);
		auto found = cardDeck.find(input);
		if (found == cardDeck.end()) cardDeck.insert({ input, 1 });
		else ++found->second;
	}
	printf("%lld\n", std::max_element(cardDeck.begin(), cardDeck.end(), compare)->first);
}
