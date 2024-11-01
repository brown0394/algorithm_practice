class Solution {
public:
    string countAndSay(int n) {
        vector<string> strings(2);
        int cur = 0, last = 1;
        strings[last] = "1";
        for (int i = 1; i < n; ++i) {
            int count = 1;
            strings[cur].clear();
            for (int j = 1, len = strings[last].size(); j < len; ++j) {
                if (strings[last][j] == strings[last][j-1]) ++count;
                else {
                    strings[cur].push_back(count + '0');
                    strings[cur].push_back(strings[last][j-1]);
                    count = 1;
                }
            }
            strings[cur].push_back(count + '0');
            strings[cur].push_back(strings[last].back());
            swap(cur, last);
        }
        return strings[last];
    }
};