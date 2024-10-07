class Solution {
    int substrToRemove(string& s, int left, int right) {
        while (left >= 0 && right < s.size()) {
            if (s[left] != 'A') {
                if (s[left] != 'C' || s[right] != 'D') break;
            }
            else if (s[right] != 'B') break;
            --left; ++right;
        }
        s.erase(left + 1, right - left - 1);
        if (left < 0) return 0;
        return left;
    }
public:
    int minLength(string s) {
        int idx = 0;
        while (idx < s.size()) {
            if (s[idx] == 'A' && idx + 1 < s.size() && s[idx + 1] == 'B') {
                idx = substrToRemove(s, idx, idx + 1);
            }
            else if (s[idx] == 'C' && idx + 1 < s.size() && s[idx + 1] == 'D') {
                idx = substrToRemove(s, idx, idx + 1);
            }
            else ++idx;
        }
        return s.size();
    }
};