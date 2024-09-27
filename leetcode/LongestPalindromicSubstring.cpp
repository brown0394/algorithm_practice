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
        std::string manachStr{'#'};
        for (char c : s) {
            manachStr.push_back(c);
            manachStr.push_back('#');
        }
        std::vector<int> palindromeLen(manachStr.size());
        int rightEnd = 0;
        int palindromeCenter = 0;
        int longestIdx = 1;
        for (int i = 0, len = manachStr.size(); i < len; ++i) {
            int leftSide = 0;
            if (rightEnd > i) {
                if (i + palindromeLen[palindromeCenter - (i - palindromeCenter)] < rightEnd) {
                    palindromeLen[i] = palindromeLen[palindromeCenter - (rightEnd - palindromeCenter)];
                    continue;
                }
                else leftSide = i - (++rightEnd - i);
            }
            else {
                leftSide = i - 1;
                rightEnd = i + 1;
            }
            palindromeCenter = i;
            while (leftSide >= 0 && rightEnd < len && manachStr[leftSide] == manachStr[rightEnd]) {
                ++rightEnd;
                --leftSide;
            }
            palindromeLen[i] = --rightEnd - i;
            if (palindromeLen[longestIdx] < palindromeLen[i]) longestIdx = i;
        }
        return s.substr((longestIdx >> 1) - (palindromeLen[longestIdx] >> 1), palindromeLen[longestIdx]);
    }
};