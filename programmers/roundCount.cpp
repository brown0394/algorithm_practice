#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int big = b;
    int small = a;
    if (a > b) {
        big = a;
        small = b;
    }
    int half = n;
    int base = 0;
    while (true) {
        half = half >> 1;
        if (small <= base + half && big > base + half) {
            int count = 1;
            while(half > 1) {
                half = half >> 1;
                ++count;
            }
            answer = count;
            break;
        }
        else {
            if (small > base + half) {
                base += half;
            }
        }
    }
    return answer;
}