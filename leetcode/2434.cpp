class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> alphaCount;
        int size = s.size();
        string ans;
        ans.resize(size);
        int idx = 0;
        stack<char> stk;
        char minC = 'a';
        for (int ii = 0; ii < size; ++ii)
        {
            ++alphaCount[s[ii]];
        }
        for (int ii = 0; ii < size; ++ii)
        {
            stk.push(s[ii]);
            --alphaCount[s[ii]];

            while (alphaCount[minC] == 0 && minC < 'z')
            {
                ++minC;
            }
            while (stk.empty() == false && stk.top() <= minC)
            {
                ans[idx++] = stk.top();
                stk.pop();
            }
        }
        return ans;
    }
};