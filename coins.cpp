#include <iostream>

int main() {
    int coinTypes;
    long long targetAmount;
    int coins[100];//[coinTypes];
    scanf("%d %d", &coinTypes, &targetAmount);
    for (int i = 0; i < coinTypes; ++i) {
        scanf("%d", &coins[i]);
    }
    int count = 0;
    for (int i = coinTypes-1; i >= 0; --i) {
        if (coins[i] > targetAmount) {
            continue;
        }
        int amount = targetAmount / (double)coins[i];
        count += amount;
        targetAmount -= (coins[i] * amount);
        if (targetAmount == 0) break;
    }
    printf("%d\n", count);
}