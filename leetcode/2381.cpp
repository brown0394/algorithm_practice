class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shiftCounts(s.size()+1);
        for (vector<int>& v : shifts) {
            if (v[2]) {
                ++shiftCounts[v[0]];
                --shiftCounts[v[1]+1];
            }
            else {
                --shiftCounts[v[0]];
                ++shiftCounts[v[1]+1];
            }
        }
        int curshift = 0;
        for (int i = 0, size = s.size(); i < size; ++i) {
            curshift = (curshift + shiftCounts[i]) % 26;
            if (curshift == 0) continue;
            int cur = s[i] - 'a';
            if (curshift < 0) {
                if (cur + curshift < 0) cur += 26;
                cur += curshift;
            }
            else cur = (cur + curshift) % 26;
            s[i] = cur + 'a'; 
        }
        return s;
    }
};