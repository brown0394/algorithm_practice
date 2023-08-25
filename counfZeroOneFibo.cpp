#include <iostream>

class zeroOne {
private:
    int one;
    int zero;
public:
    zeroOne operator+(zeroOne& other);
    zeroOne(int zero, int one);
    zeroOne();
    void print();
};
zeroOne::zeroOne(int p_zero, int p_one) : zero(p_zero), one(p_one){
}

zeroOne::zeroOne(){}

zeroOne zeroOne::operator+(zeroOne& other) {
    return zeroOne(this->zero + other.zero, this->one + other.one);
}

void zeroOne::print() {
    printf("%d %d\n", this->zero, this->one);
}



void fibonacci(int n, zeroOne* fibo, int done) {
    if (n > done) {
        for (int i = done + 1; i <= n; ++i) {
            fibo[i] = fibo[i - 1] + fibo[i-2];
        }
        done = n;
    }
    fibo[n].print();
}

int main() {
    zeroOne fiboZeroOne[40];
    fiboZeroOne[0] = zeroOne(1, 0);
    fiboZeroOne[1] = zeroOne(0, 1);
    fiboZeroOne[2] = zeroOne(1, 1);
    int done = 2;
    int N;
    scanf("%d", &N);
    int prob;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &prob);
        fibonacci(prob, fiboZeroOne, done);
    }
}

