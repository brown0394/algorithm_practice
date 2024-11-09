class Solution {
public:
    long long minEnd(int n, int x) {
        long long last = x;
        long long bit = 1;
        --n;
        for (long long i = 1; i <= n; i <<= 1) {
            while(bit & last) bit <<= 1;
            if (i & n) last |= bit;
            bit <<= 1;
        }
        return last;
    }
};