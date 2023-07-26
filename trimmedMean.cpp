#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>

int main() {
    int num, mean;
    scanf("%d", &num);
    std::vector<int> arr(num);
    if (!num) {
        mean = num;
    }
    else {
        for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
            scanf("%d", &(*it));
        }
        std::sort(arr.begin(), arr.end());
        int trim = std::round(num * 0.15f);
        int sum = 0;
        sum = std::accumulate(arr.begin() + trim, arr.end() - trim, 0);
        num -= (trim * 2);
        mean = std::round(sum / static_cast<float>(num));
    }

    printf("%d\n", mean);
}