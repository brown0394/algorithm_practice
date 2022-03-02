#include <iostream>
#include <math.h>

int main() {
    int target = 0;
    std::cin >> target;
    bool zero = false;
    int last = 0;
    int ans = 0;
    for (int i = 1; i < target; ++i) {
            if (i == 245) {
        int asd = 1;
    }
        int num = i;
        int digit = 0;
        int divadd = i;
        while(num > 0) {
            num /= 10;
            ++digit;
        }
        num = i;
        int b = 0;
        for (int j = 0; j < digit; ++j) {
            int a = pow(10, digit-(j+1));
            b = num / a;
            num -= a * b;
            divadd += b;
        }
        if (b == 0){
            last = divadd;
        }
        if (divadd == target) {
            ans = i;
            break;
        }
        else if (last > target){
            break;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}