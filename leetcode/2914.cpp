class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        for (int i = 1, len = s.size(); i < len; i += 2) {
            if (s[i] != s[i-1]) ++changes;
        }
        return changes;
    }
};