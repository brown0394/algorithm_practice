#include <iostream>
#include <vector>

struct node {
    int num;
    int count;
    bool operator < (const node& other) {
        return this->num > other.num;
    }
};

bool findCombination(int target, int sum, int i, std::vector<node>& coins) {
    if (i == coins.size()) return false;
    for (int j = 0; j < coins[i].count; ++j) {
        sum += coins[i].num;
        if (sum == target) return true;
        if (sum < target && findCombination(target, sum, i + 1, coins)) return true;
    }
    return false;
}

int main() {
    std::vector<node> coins;
    for (int i = 0; i < 3; ++i) {
        int n;
        scanf_s("%d", &n);
        coins.resize(n);
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            scanf_s("%d %d", &coins[j].num, &coins[j].count);
            sum += (coins[j].num * coins[j].count);
        }
        if (sum % 2) {
            printf("0\n");
            coins.clear();
            continue;
        }
        sum >>= 1;
        if (findCombination(sum, 0, 0, coins)) printf("1\n");
        else printf("0\n");
    }
}