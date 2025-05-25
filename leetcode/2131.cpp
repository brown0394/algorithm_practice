class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int size = words.size();
        int sameOdd = 0;
        int ans = 0;
        unordered_map<char, unordered_map<char, int>> wordPair;
        for (int i = 0; i < size; ++i)
        {
            if (words[i][0] == words[i][1])
            {
                ++wordPair[words[i][0]][words[i][0]];
                if (wordPair[words[i][0]][words[i][0]] % 2 == 0)
                {   
                    ans += 4;
                    --sameOdd;    
                }
                else
                    ++sameOdd;
                continue;
            }
            if (wordPair[words[i][1]][words[i][0]] > 0)
            {
                --wordPair[words[i][1]][words[i][0]];
                ans += 4;
                continue;
            }

            ++wordPair[words[i][0]][words[i][1]];
        }

        if (sameOdd > 0)
            ans += 2;
            
        return ans;
    }
};