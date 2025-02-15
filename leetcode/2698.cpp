class Solution {
    bool check(int cur, int sum, int target)
    {
        if (sum + cur == target)
            return true;
        int l = cur % 10;
        int r = cur / 10;
        int next = 10;
        while (r > 0)
        {
            if (sum + l > target)
                return false;
            if (check(r, sum + l, target) == true)
                return true;
            l += ((r % 10) * next);
            next *= 10;
            r /= 10;
        }
        return false;
    }

public:

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int square = i * i;
            if (check(square, 0, i) == true)
                ans += square;
        }
        return ans;
    }
};