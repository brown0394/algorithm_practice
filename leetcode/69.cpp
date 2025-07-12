class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        long long till = x >> 1;
        int ans = 1;
        long long low = 1;
        while (low <= till)
        {
            long long mid = (till + low) >> 1;
            if (mid * mid <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                till = mid - 1;
        }
        return ans;
    }
};