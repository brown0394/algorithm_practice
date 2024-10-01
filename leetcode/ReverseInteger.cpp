class Solution {
public:
    int reverse(int x) {
        long newVal = 0;
        while (x) {
            newVal *= 10;
            newVal += x % 10;
            x /= 10;
        }
        if (newVal > numeric_limits<int>::max() || newVal < numeric_limits<int>::min()) return 0;
        return newVal;
    }
};