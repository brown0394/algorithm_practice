#include <iostream>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int gcd = b;
    int sec = b;
    int remainder = a % b;

    while (remainder) {
        gcd = remainder;
        remainder = sec % remainder;
        sec = gcd;
    }
    int lcd = (a * b) / gcd;
    printf("%d\n%d\n", gcd, lcd);

}