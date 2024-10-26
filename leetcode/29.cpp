class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) {
            return dividend;
        }
        else if (divisor == -1) {
            if (dividend == -2147483648) return 2147483647;
            return -dividend;
        }
        int sign = 1;
        long long divid = dividend, divis = divisor;
        if (divisor < 0) {
            sign = -1;
            divis = divisor;
            divis = -divis;
        }
        if (dividend < 0) {
            sign = -sign;
            divid = dividend;
            divid = -divid;
        }
        long long add = divis;
        unsigned int i = 0;
        for (; divid >= add; ++i) {
            add += divis;
        }
        if (sign < 0) {
            return -i;
        }
        return i;
    }
};