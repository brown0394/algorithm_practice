class Solution {
    bool isVowel(char c) {
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u' : {return true;}
        }
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSums(words.size()+1);
        for (int i = 1, size = words.size(); i <= size; ++i) {
            prefixSums[i] = prefixSums[i-1];
            if (isVowel(words[i-1].front()) && isVowel(words[i-1].back())) ++prefixSums[i];
        }
        vector<int> ans(queries.size());
        for (int i = 0, size = queries.size(); i < size; ++i) {
            ans[i] = prefixSums[queries[i][1]+1] - prefixSums[queries[i][0]];
        }
        return ans;
    }
};