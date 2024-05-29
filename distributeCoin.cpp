#include <iostream>
#include <vector>
#include <bitset>

struct node {
    int num;
    int count;
    bool operator < (const node& other) {
        return this->num > other.num;
    }
};

bool findCombination(int target, std::vector<node>& coins) {
    int size = coins.size();
    std::vector<std::bitset<50005>> available(size + 1);
    available[0][0] = true;
    int lastMax = 0;
    int plus = 1;
    for (int i = 1; i <= size; ++i) {
        int curMax = 0;
        for (int j = 0; j <= lastMax; ++j) {
            if (available[i-1][j]) {
                available[i][j] = true;
                int adder = 0;
                for (int k = 0; k < coins[i-1].count; ++k) {
                    if (j + adder + coins[i - 1].num <= target) adder += coins[i - 1].num;
                    else break;
                    available[i][j + adder] = true;
                }
                if (j + adder > curMax) curMax = j + adder;
            }
        }
        if (lastMax < curMax) lastMax = curMax;
    }
    return available[size][target];
}

int main() {
    std::vector<node> coins;
    for (int i = 0; i < 3; ++i) {
        int n;
        scanf("%d", &n);
        coins.resize(n);
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            scanf("%d %d", &coins[j].num, &coins[j].count);
            sum += (coins[j].num * coins[j].count);
        }
        if (sum % 2) {
            printf("0\n");
            coins.clear();
            continue;
        }
        sum >>= 1;
        if (findCombination(sum, coins)) printf("1\n");
        else printf("0\n");
        coins.clear();
    }
}