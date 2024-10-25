class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        for (int i = 0, len = haystack.size() - n; i <= len; ++i) {
            if (haystack[i] == needle[0]) {
                int j = 1;
                for (; j < n; ++j) {
                    if (haystack[i + j] != needle[j]) break;
                }
                if (j == n) return i;
            }
        }
        return -1;
    }
};