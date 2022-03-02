#include <iostream>

int main() {
    int one, two;
    std::cin >> one >> two;
    int primesum = 0, min = 0;

    for (int i = one; i <= two; ++i) {
        int num = 2;
        bool is_prime = true;
        if (i > 1) {
            while (num <= i / 2) {
                if (i % num == 0) {
                    is_prime = false;
                    break;
                }
                ++num;
            }
            if (is_prime) {
                if (min == 0) {
                    min = i;
                }
                primesum += i;
            }
        }
    }
    if (min == 0) {
        std::cout << -1 << '\n';
    }
    else {
        std::cout << primesum << '\n' << min << '\n';
    }
}