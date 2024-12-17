class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        sort(s.rbegin(), s.rend());
        string ans;
        int size = s.size();
        ans.reserve(size);
        int cur = 0;
        int count = 0;
        int next = 1;
        while (next < size && s[next] == s[cur]) ++next;
        while (cur < size) {
            do {
                ans.push_back(s[cur++]);
                ++count;
            } while(cur < size && count < repeatLimit && s[cur] == s[cur - 1]);
            if (next == size) break;
            count = 0;
            if (cur < size && s[cur] != s[cur-1]) {
                cur = next;
                while (next < size && s[next] == s[cur]) ++next;
            }
            else ans.push_back(s[next++]);
        }
        return ans;
    }
};