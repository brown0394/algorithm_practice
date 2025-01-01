class Solution {
public:
    int maxScore(string s) {
        int l = 0;
        if (s[0] == '0') ++l;
        int r = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '1') ++r;
        }
        int score = l + r;
        int maxScore = score;
        for (int i = 1; i < s.size()-1; ++i) {
            if (s[i] == '0') ++l;
            else --r;
            maxScore = max(maxScore, l + r);
        }
        return maxScore;
    }
};