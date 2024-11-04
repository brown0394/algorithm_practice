class Solution {
public:
    string compressedString(string word) {
        string ans;
        for (int i = 0, len = word.size(); i < len;) {
            int j = i + 1;
            while (j < len && word[i] == word[j]) ++j;
            int count = j - i;
            int nines = count / 9;
            int ones = count % 9;
            while (nines) {
                ans.push_back('9');
                ans.push_back(word[i]);
                --nines;
            }
            if (ones) {
                ans.push_back(ones + '0');
                ans.push_back(word[i]);
            }
            i = j;
        }
        return ans;
    }
};