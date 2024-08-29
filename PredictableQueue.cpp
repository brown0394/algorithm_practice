#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int works, cases;
    std::cin >> works >> cases;

    std::vector<int> workArr(works + 1);
    for (int i = 1; i <= works; ++i) {
        std::cin >> workArr[i];
        workArr[i] += workArr[i - 1];
    }
    auto first = workArr.begin();
    for (int i = 0, timeToWork; i < cases; ++i) {
        std::cin >> timeToWork;
        if (timeToWork == 0) {
            std::cout << 0 << '\n';
            continue;
        }
        auto found = std::upper_bound(first, workArr.end(), timeToWork) - 1;
        std::cout << found - first << '\n';
    }
}