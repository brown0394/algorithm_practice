class Solution {
public:
    bool checkPowersOfThree(int n) {
        int cur = 1;
        while (cur * 3 <= n)
        {
            cur *= 3;
        }
        while (cur > 0)
        {
            if (cur <= n)
                n -= cur;
            cur /= 3;
        }
        return n == 0;
    }
};