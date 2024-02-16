#include <iostream>
#include <vector>

int main() {
	int numOfCards;
	scanf_s("%d\n", &numOfCards);
	std::vector<int> cardPrices(numOfCards + 1);
	for (int i = 1; i <= numOfCards; ++i) {
		scanf_s("%d", &cardPrices[i]);
		int idxH = i - 1;
		int idxL = 1;
		while (idxH >= idxL) {
			if (cardPrices[i] < cardPrices[idxH] + cardPrices[idxL])
				cardPrices[i] = cardPrices[idxH] + cardPrices[idxL];
			--idxH;
			++idxL;
		}
	}
	printf("%d\n", cardPrices[numOfCards]);
}
