class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> counts(1001);
        int ans = 0;
        for (int i = 0; i < answers.size(); ++i)
        {
            ++counts[answers[i]];
        }
        
        for (int i = 0; i < 1001; ++i)
        {
            if (counts[i] == 0)
                continue;
            int plOne = i + 1;
            ans += ((counts[i] / plOne) * plOne);
            if ((counts[i] % plOne) > 0)
                ans += plOne;
        }
        return ans;
    }
};