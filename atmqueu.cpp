#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    scanf("%d", &N);
    std::vector<int> times(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &times[i]);
    }
    std::sort(times.begin(), times.end());
    int sum=0, partialSum=0;
    for (auto it = times.begin(); it != times.end(); ++it) {
        partialSum += *it;
        sum += partialSum;
    }
    printf("%d\n", sum);

}