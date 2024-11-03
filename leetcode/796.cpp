class Solution {
public:
    bool rotateString(string s, string goal) {
        int slen = s.size(), glen = goal.size();
        if (slen != glen) return false;
        int idx = 0;
        for (; idx < glen; ++idx) {
            if (s[0] == goal[idx]) {
                int cur = idx;
                for (int j = 0; j < slen; ++j) {
                    if (s[j] != goal[cur]) break;
                    cur = (cur + 1) % glen;
                }
                if (cur == idx) return true;
            }
        }
        return false;
    }
};