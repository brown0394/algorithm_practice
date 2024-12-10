class Solution {
public:
    int maximumLength(string s) {
        int len = s.size();
        int idx = 0;
        int maxLen = 0;
        vector<vector<int>> counts(26, vector<int>(3, 0));
        while (idx < len) {
            int next = idx + 1;
            while (next < len && s[next] == s[idx]) ++next;
            int num = next - idx;
            int sidx = s[idx]-'a';
            if (num > counts[sidx][0]) {
                counts[sidx][1] = counts[sidx][0];
                counts[sidx][0] = num;
            }
            else if (num > counts[sidx][1]) {
                counts[sidx][2] = counts[sidx][1];
                counts[sidx][1] = num;
            }
            else if (num > counts[sidx][2]) counts[sidx][2] = num;
            idx = next;
        }
        for (int i = 0; i < 26; ++i) {
            if (counts[i][0] + counts[i][1] +counts[i][2] < 3) continue;
            if (!maxLen) maxLen = 1;
            if (counts[i][0] == counts[i][2]) maxLen = max(maxLen, counts[i][0]);
            else if (counts[i][0] - counts[i][1] <= 1) maxLen = max(maxLen, counts[i][0] - 1);
            else maxLen = max(maxLen, counts[i][0] - 2);
        }
        if (maxLen == 0) return -1;
        return maxLen;
    }
};