class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (x == 1) return 1;
        double val = 1;
        bool neg = false;
        long long till = n;
        if (till < 0) {
            neg = true;
            till = -till;
        }       
        while (till) {
            if (till & 1) {
                val *= x;
            }
            x *= x;
            till >>= 1;
        }
        if (neg) {
            val = 1 / val;
        }
        return val;
    }
};