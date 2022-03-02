#include <iostream>

int main() {
    int num;
    std::cin >> num;
    if (num > 1) {
        while (num > 1) {
            int quot = 2;
            while (num % quot != 0) {
                ++quot;
                if (quot > num / 2) {
                    quot = num;
                    break;
                }
            }
            std::cout << quot << '\n';
            num /= quot;
        }
    }
}