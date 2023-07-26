#include <iostream>

int main() {
    int N;
    scanf("%d", &N);
    int count[10001]{0};
    int in = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &in);
        ++count[in];
    }
    for (int i = 1; i <= 10000; ++i) {
        if (count[i]) {
            for (int j = 0; j < count[i]; ++j) {
                printf("%d\n", i);
            }
        }
    }
}