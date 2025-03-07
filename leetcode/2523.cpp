class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> sieve(right + 1, 1);
        sieve[0] = 0;
        sieve[1] = 0;
        for (int i = 2; (i * i) <= right; ++i)
        {
            if (sieve[i] == 0)
                continue;
            for (int j = i * i; j <= right; j += i)
            {
                sieve[j] = 0;
            }
        }
        int idx = 0;
        for (int i = 2; i <= right; ++i)
        {
            if (sieve[i] == 1)
            {
                sieve[idx++] = i;
            }
        }
        vector<int> ans{-1, -1};
        auto found = lower_bound(sieve.begin(), sieve.begin()+idx, left);
        int cur = found - sieve.begin() + 1;
        if (cur >= idx) return ans;
        ans[0] = sieve[cur-1];
        ans[1] = sieve[cur++];
        for (; cur < idx; ++cur)
        {
            if (ans[1] - ans[0] > sieve[cur] - sieve[cur-1])
            {
                ans[0] = sieve[cur-1];
                ans[1] = sieve[cur];
            }
        }
        return ans;
    }
};