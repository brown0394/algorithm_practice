class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans;
        int size = s.size();
        ans.reserve(size);
        int counts[26]{0};
        for (int i = 0; i < size; ++i) {
            ++counts[s[i] - 'a'];
        }
        int cur = 25;
        while (cur >= 0 && !counts[cur]) --cur;
        int count = 0;
        int next = cur-1;
        while (next >= 0 && !counts[next]) --next;
        while (cur >= 0) {
            do {
                --counts[cur];
                ans.push_back(cur + 'a');
                ++count;
            } while(cur >= 0 && count < repeatLimit && counts[cur]);
            if (next < 0) break;
            count = 0;
            if (cur >= 0 && !counts[cur]) {
                cur = next--;
            }
            else {
                ans.push_back(next + 'a');
                --counts[next];
            }
            while (next >= 0 && !counts[next]) --next;
        }
        return ans;
    }
};