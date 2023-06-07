#include <iostream>

int main() {
    int size = 3;
    int n;
    char number[10]{0};
    int idx;
    number[9] = number[8] = number[7] = '6';
    scanf("%d", &n);
    while (true) {
        int lim = 9-size;
        for (int i = 9; i > lim + 2; --i) {
            if (number[i] == '6' && '6' == number[i-1] && number[i-2] == '6') {
                --n;
                break;
            }
        }
        if (!n) break;
        idx = 9;
        while (idx >= 0) {
            if (number[idx] == '9') {
                number[idx] = '0';
                --idx;
            }
            else {
                break;
            }
        }
        if (idx == lim) {
            number[idx] = '0';
            ++size;
        }
        ++number[idx];
    }

    for (int i = 10 - size; i < 10; ++i) {
        putchar(number[i]);
    }
    putchar('\n');
}