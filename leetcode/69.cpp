class Solution {
public:
    int mySqrt(int x) {
        if (x == 1)
            return 1;
        int till = x >> 1;

        long long cur = 1;
        while (cur <= till)
        {
            if (cur * cur > x)
                return cur -1;

            ++cur;
        }
        return till;
    }
};