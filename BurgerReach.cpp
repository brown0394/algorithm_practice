#include <iostream>
#include <queue>

bool isReachable(std::queue<int>& target, int i, int reach) {
    while (!target.empty()) {
        if (i - target.front() <= reach) {
            target.pop();
            return true;
            break;
        }
        else target.pop();
    }
    return false;
}

int main() {
    std::queue<int> burger;
    std::queue<int> eater;
    int len, reach;
    scanf_s("%d %d", &len, &reach);
    char in;
    getchar();
    int count = 0;
    for (int i = 0; i < len; ++i) {
        scanf_s("%c", &in);
        bool ate = false;
        if (in == 'H') {
            if (!isReachable(eater, i, reach)) burger.push(i);
            else ++count;
        }
        else {
            if (!isReachable(burger, i, reach)) eater.push(i);
            else ++count;
        }
    }
    printf("%d\n", count);
}