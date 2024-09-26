class Solution {
    int checkPalindrome(int& left, int& right, int add, std::string& s) {
        int len = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            len += 2;
            --left;
            ++right;
        }
        if (len) return len + add;
        return 0;
    }
public:
    std::string longestPalindrome(std::string s) {
        int start = 0, end = 0;
        for (int i = 0, size = s.size() - 1; i < size; ++i) {
            int left = i, right = i + 1;
            if (checkPalindrome(left, right, 0, s) > ((end - start) + 1)) {
                start = left + 1;
                end = right - 1;
            }
            if (i) {
                left = i - 1;
                right = i + 1;
                if (checkPalindrome(left, right, 1, s) > ((end - start) + 1)) {
                    start = left + 1;
                    end = right - 1;
                }
            }

        }
        return s.substr(start, (end - start) + 1);
    }
};