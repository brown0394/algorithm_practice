class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        int left = 0, right = 0;
        int len = s.size();
        int maxRemoval = 0;
        int counts[3]{0};
        for (int i = 0; i < len; ++i) {
            ++counts[s[i]-'a'];
        }
        if (counts[0] < k || counts[1] < k || counts[2] < k) return -1;
        while (right < len) {
            if (counts[s[right]-'a'] > k) {
                --counts[s[right]-'a'];
                ++right;
            }
            else {
                maxRemoval = max(maxRemoval, right - left);
                ++counts[s[left]-'a'];
                ++left;
            }
        }
        if (left < right) maxRemoval = max(maxRemoval, right - left);
        return len - maxRemoval;
    }
};