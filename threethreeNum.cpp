#include <iostream>
long long threes[40];
int len = 1;
long long target;
bool checkIsThreeNum(int idx, long long sum) {
    if (sum == 0) return true;
    for (; idx >= 0; --idx) {
        if (sum - threes[idx] >= 0) {
            if (threes[idx] << 1 < sum) break;
            if (checkIsThreeNum(idx - 1, sum - threes[idx])) return true;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    threes[0] = 1;
    
    
    std::cin >> target;
    for (; len < 40; ++len) {
        threes[len] = threes[len - 1] * 3;
        if (threes[len] > target) break;
    }
    for (int i = len - 1; i >= 0; --i) {
        if (threes[i] << 1 < target) break;
        if (checkIsThreeNum(i - 1, target - threes[i])) {
            std::cout << "YES\n";
            return 0;
        }
    }
    std::cout << "NO\n";
}