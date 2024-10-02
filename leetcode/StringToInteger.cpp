class Solution {
public:
    int myAtoi(string s) {
        int retVal = 0;
        int sign = 1;
        int len = s.size();
        int idx = 0;
        while (idx < len && s[idx] == ' ') ++idx;
        if (idx >= len) return 0;
        if (s[idx] == '-') {
            sign = -1;
            ++idx;
        }
        else if (s[idx] == '+') ++idx;
        int limit = numeric_limits<int>::max() / 10;
        while (idx < len && s[idx] >= '0' && s[idx] <= '9') {
            if (retVal > limit) {
                if (sign < 0) return numeric_limits<int>::min();
                return numeric_limits<int>::max();
            }
            else if (retVal == limit) {
                if (sign > 0 && s[idx] >= '7') return numeric_limits<int>::max();
                if (sign < 0 && s[idx] >= '8') return numeric_limits<int>::min();
            }
            retVal *= 10;
            retVal += s[idx++] - '0';
        }
        return retVal * sign;
    }
};