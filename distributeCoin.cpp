#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

struct node {
    int num;
    int count;
    bool operator < (const node& other) {
        return this->num > other.num;
    }
};

int main() {
    std::vector<node> coins;
    for (int i = 0; i < 3; ++i) {
        int n;
        scanf_s("%d", &n);
        coins.resize(n);
        for (int j = 0; j < n; ++j) {
            scanf_s("%d %d", &coins[j].num, &coins[j].count);
        }
        std::sort(coins.begin(), coins.end());
        for (int j = 0; j < n; ++j) {
            std::stack<int> stk;
            if (coins[j].count % 2) {

            }
        }
    }
}