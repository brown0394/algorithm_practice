#include <iostream>
#include <map>

int main() {
    int cardsOwned, cardsToCheck;
    std::map<int, int> cardCount;
    scanf("%d", &cardsOwned);
    int num;
    std::map<int, int>::iterator found;
    for (int i = 0; i < cardsOwned; ++i) {
        scanf("%d", &num);
        found = cardCount.find(num);
        if (found == cardCount.end()) {
            cardCount.insert(std::make_pair(num, 1));
        }
        else {
            ++(found->second);
        }
    }

    scanf("%d", &cardsToCheck);

    for (int i = 0; i < cardsToCheck; ++i) {
        if (i) putchar(' ');
        scanf("%d", &num);
        found = cardCount.find(num);
        if (found == cardCount.end()) {
            putchar('0');
        }
        else {
            printf("%d", found->second);
        } 
    }
}