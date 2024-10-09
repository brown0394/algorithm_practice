class Solution {
public:
    int minAddToMakeValid(string s) {
        int openings = 0, closings = 0;
        for (int i = 0, len = s.size(); i < len; ++i) {
            if (s[i] == '(') ++openings;
            else {
                if (openings) --openings;
                else ++closings; 
            }
        }
        return openings + closings;
    }
};