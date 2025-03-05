class Solution {
public:
    long long coloredCells(int n) {
        long long cur = 1;
        long long plus = 4;
        while (1 < n)
        {
            cur += plus;
            plus += 4;
            --n;
        }
        return cur;
    }
};