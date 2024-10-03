class Solution {
    bool checkStar(string& s, string& p, int pIdx, int sIdx, char preceding) {
        while (pIdx < p.size()) {
            if (sIdx == s.size()) {
                if (p[pIdx] != '*') return false;
                ++pIdx;
                while (pIdx < p.size() && p[pIdx] == '*') ++pIdx;
                continue;
            }
            if (p[pIdx] == '*') {
                if (!preceding && pIdx) {
                    preceding = p[pIdx - 1];
                    while (pIdx + 1 < p.size() && p[pIdx + 1] == '*') ++pIdx;
                }
                else {
                    if (preceding == '.' || preceding == s[sIdx]) {
                        if (checkStar(s, p, pIdx, sIdx + 1, preceding)) return true;
                    }
                    ++pIdx;
                    preceding = 0;
                }
            }
            else if (p[pIdx] != s[sIdx] && p[pIdx] != '.') return false;
            else {
                ++pIdx;
                ++sIdx;
            }
        }
        return sIdx == s.size();
    }
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0;
        while (pIdx < p.size() && sIdx < s.size() && p[pIdx] != '.' && p[pIdx] != '*') {
            if (s[sIdx] != p[pIdx]) return false;
            ++sIdx; ++pIdx;
        }
        return checkStar(s, p, pIdx, sIdx, 0);
    }
};