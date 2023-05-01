#include <iostream>

int main() {
    long long numOfWoods, woodsNeeded;
    scanf("%lld %lld", &numOfWoods, &woodsNeeded);

    long long *woods = new long long[numOfWoods];
    long long highest = 0;
    for(long long i = 0; i < numOfWoods; ++i) {
        scanf("%lld", &woods[i]);
        if (woods[i] > highest) {
            highest = woods[i];
        }
    }

    long long mid = 0;
    long long low = 0;
    long long sum;
    int ans = 0;
    while (low <= highest) {
        sum = 0;
        mid = (highest + low) / 2;
        for (long long i = 0; i < numOfWoods; ++i) {
            if (woods[i] > mid){
                sum += (woods[i] - mid);
            }
        }
        if (sum >= woodsNeeded) {
            low = mid + 1;
            if (ans < mid) {
                ans = mid;
            }
        }
        else {
            highest = mid - 1;
        }
    }

    printf("%lld\n", ans);
    delete[] woods;
}