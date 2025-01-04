class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> lastIdx(26, -1);
        vector<bitset<26>> checked(26);
        vector<int> counts(26);
        int ans = 0;
        for (int i = 0, size = s.size(); i < size; ++i) {
            int idx = s[i] - 'a';
            ++counts[idx];
            if (counts[idx] == 3) ++ans;
            if (lastIdx[idx] < 0) {
                lastIdx[idx] = i;
                continue;
            }
            for (int j = lastIdx[idx]+1; j < i; ++j) {
                if (!checked[idx][s[j]]) {
                    checked[idx][s[j]] = true;
                    ++ans;
                }
            }
            lastIdx[idx] = i;
        }
        return ans;
    }
};