#include <iostream>

int main() {
    int inputs = 0;
    int lanNumNeeded = 0;
    scanf("%d %d", &inputs, &lanNumNeeded);

    int arr[10001];
    long long avg = 0;

    for (int i = 0; i < inputs; ++i) {
        scanf("%d", &arr[i]);
        avg += arr[i];
    }
    avg /= (double)lanNumNeeded;
   // printf("\n\n%ld\n", avg);
    int lastAvg = avg;
    int divisor = avg >> 1;
    int lastDiv = -1;
    int sum;
    while(true) {
        sum = 0;
        for (int i = 0; i < inputs; ++i) {
            sum += (arr[i] / avg);
        }
        if (sum < lanNumNeeded) {
            if (lastDiv == 0) {
                --avg;
                break;
            }
            avg -= (divisor+1);
        }
        else {
            avg += (divisor+1);
        }
        lastDiv = divisor;
        divisor = divisor >> 1;
       // printf("%ld\n", avg);
    }
    printf("%ld\n", avg);
}