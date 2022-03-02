#include <iostream>

int main() {
    int one = 4, two = 10000;
    bool* arr = new bool[two + 1]{ false };
    arr[0] = true;
    arr[1] = true;
    for (int i = 2; i < two + 1; ++i) {
        if (!arr[i]) {
            int num = i * 2;
            int count = 2;
            while (num <= two) {
                arr[num] = true;
                ++count;
                num = i * count;
            }
        }
    }

    int cases;
    std::cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int input;
        std::cin >> input;
        int half = input / 2;
        if (!arr[half]) {
            std::cout << half << ' ' << half << std::endl;
        }
        else {
            int dwncnt = 1;
            while (arr[half - dwncnt]) {
                ++dwncnt;
            }
            while (true) {
                if (!arr[input - (half - dwncnt)]) {
                    break;
                }
                else {
                    ++dwncnt;
                    while (arr[half - dwncnt] ) {
                        ++dwncnt;
                    }
                }
            }
            std::cout << half - dwncnt << ' ' << input - (half - dwncnt) << std::endl;
        }
    }
    delete[] arr;
}