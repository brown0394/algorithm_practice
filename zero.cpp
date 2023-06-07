#include <iostream>

int main() {
    int num;
    scanf("%d", &num);
    int idx = 0;
    int *arr = new int[num];
    int in;
    for (int i = 0; i < num; ++i) {
        scanf("%d", &in);
        if (in) {
            arr[idx++] = in;
        }
        else {
            --idx;
        }
    }
    int sum = 0;
    for (int i = 0; i < idx; ++i) {
        sum += arr[i];
    }
    printf("%d\n", sum);
    delete[] arr;
}