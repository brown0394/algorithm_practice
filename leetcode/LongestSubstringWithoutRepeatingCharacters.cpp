class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int duplicateCheck[130];
        memset(duplicateCheck, -1, sizeof(int) * 130);
        int max = 0;
        int left = 0, right = 0, strLen = s.size();
        while (right < strLen) {
            if (duplicateCheck[s[right]] < left) {
                duplicateCheck[s[right]] = right;
            }
            else {
                if (max < right - left) max = right - left;
                left = duplicateCheck[s[right]] + 1;
                duplicateCheck[s[right]] = right;
            }
            ++right;
        }
        if (max < right - left) max = right - left;
        return max;
    }
};