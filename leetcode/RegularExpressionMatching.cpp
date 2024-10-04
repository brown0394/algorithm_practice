class Solution {
    bool checkStar(string& s, string& p, int pIdx, int sIdx, char preceding) {
        while (pIdx < p.size()) {
            if (sIdx == s.size()) {
                if (p[pIdx] != '*' && (pIdx + 1 == p.size() || p[pIdx + 1] != '*')) {
                    return false;
                }
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
            else if (p[pIdx] != s[sIdx] && p[pIdx] != '.') {
                if (pIdx + 1 < p.size() && p[pIdx + 1] == '*') {
                    pIdx += 2;
                }
                else return false;
            }
            else {
                ++pIdx;
                if (pIdx < p.size() && p[pIdx] == '*') {
                    if (checkStar(s, p, pIdx + 1, sIdx, 0)) return true;
                }
                ++sIdx;
            }
        }
        return sIdx == s.size();
    }
public:
    bool isMatch(string s, string p) {
        return checkStar(s, p, 0, 0, 0);
    }
};