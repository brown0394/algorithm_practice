#include <iostream>

int main() {
    int num;
    scanf("%d", &num);

    int *arr = new int[num+1];
    arr[0] = 10000001;
    arr[1] = 0;

    for (int i = 2; i <= num; ++i) {
        int temp = 0;
        if (i % 3 == 0 && i % 3 == i % 2) {
            if (arr[i >> 1] >= arr[i / 3]) {
                temp = i / 3;
            }
            else {
                temp = i >> 1;
            }
        }
        else if (i % 3 == 0) {
            temp = i / 3;
        }
        else if (i % 2 == 0) {
            temp = i >> 1;
        }

        if (arr[temp] + 1 <= arr[i-1] + 1) {
            arr[i] = arr[temp] + 1;
        }
        else {
            arr[i] = arr[i-1] + 1;
        }
    }
    printf("%d\n", arr[num]);
    delete arr;
}