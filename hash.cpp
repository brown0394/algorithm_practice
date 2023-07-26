#include <iostream>
#include <cmath>
#define R 31
#define M 1234567891
int main() {
    int N;
    scanf("%d", &N);
    unsigned int sum = 0;
    int alph;
    scanf("%c", &alph);
    for (int i = 0; i < N; ++i) {
        scanf("%c", &alph);
        alph = alph - 'a' + 1;
        //sum += alph * (std::pow(R, i));

        unsigned int power = R;
        unsigned int adder = R;
        if (i == 0) {
            power = 1;
            adder = 1;
        }
        for (int j = 2; j <= i; ++j) {
            for (int k = 1; k < R; ++k) {
                power = (power + adder) % M;
            }
            adder = power;
        }

        for (int j = 1; j < alph; ++j) {
            power = (power + adder) % M;
        }
        sum = (sum + power) % M;
    }

    printf("%d\n", sum);
}