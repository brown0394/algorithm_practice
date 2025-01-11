class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() == k) return true;
        if (s.size() < k) return false;
        array<int, 26> counts{};
        for (char c : s)
        {
            ++counts[c - 'a'];
        }
        int evens = 0;
        int odds = 0;
        for (int ii = 0; ii < 26; ++ii)
        {
            if (counts[ii] % 2 == 0)
                evens += counts[ii];
            else
            {
                ++odds;
                evens += counts[ii] - 1;
            }
        }
        if (odds == k)
            return true;
        if (odds > k)
            return false;
        if (k - odds <= evens)
            return true;
        
        return false;
    }
};