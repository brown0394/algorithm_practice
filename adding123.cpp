#include <iostream>
#define ARRSIZE 12

int main() {
    int arr[ARRSIZE];
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for (int i = 4; i < ARRSIZE; ++i) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    int problems, problem;
    scanf("%d", &problems);
    for (int i = 0; i < problems; ++i) {
        scanf("%d", &problem);
        printf("%d\n", arr[problem]);
    }
}