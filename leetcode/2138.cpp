class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int size = s.size();
        int idx = 0;
        vector<string> ans;
        while (idx < size)
        {
            if (idx + k <= size)
            {
                ans.push_back(s.substr(idx, k));
                idx += k;
            }
            else
            {
                string str = s.substr(idx, size - idx);
                int till = k - (size - idx);
                for (int i = 0; i < till; ++i)
                {
                    str.push_back(fill);
                }
                ans.push_back(str);
                break;
            }
        }
        return ans;
    }
};