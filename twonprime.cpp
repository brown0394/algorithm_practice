#include <iostream>

int main() {
    int one, two;
    std::cin >> one >> two;
    int dist = two - one;
    bool* arr = new bool[two+1] {false};
    //bool arr[two + 1]{ false };
    arr[0] = true;
    arr[1] = true;
    for (int i = 2; i < two+1; ++i) {
        if (!arr[i]) {
            if (i >= one) {
                std::cout << i << '\n';
            }
            int num = i * 2;
            int count = 2;
            while (num <= two) {
                arr[num] = true;
                ++count;
                num = i * count;
            }
        }
    }
    delete[] arr;
}