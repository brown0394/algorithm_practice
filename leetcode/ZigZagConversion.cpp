class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        std::string result;
        int len = s.size();
        result.reserve(len);
        int idx = 0;
        int down = (numRows - 1) << 1;
        while (idx < len) {
            result.push_back(s[idx]);
            idx += down;
        }
        int up = 2;
        down -= 2;
        for (; down > 0; down -= 2) {
            idx = up >> 1;
            bool turn = true;
            while (idx < len) {
                result.push_back(s[idx]);
                if (turn) {
                    turn = false;
                    idx += down;
                }
                else {
                    turn = true;
                    idx += up;
                }
            }
            up += 2;
        }
        idx = up >> 1;
            while (idx < len) {
            result.push_back(s[idx]);
            idx += up;
        }
        return result;
    }
};