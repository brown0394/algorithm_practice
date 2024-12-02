class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordCount = 1;
        int wordLen = searchWord.size();
        bool check = true;
        for (int i = 0, len = sentence.size() - wordLen; i <= len; ++i) {
            if (sentence[i] == ' ') {
                ++wordCount;
                check = true;
                continue;
            }
            if (check && sentence[i] == searchWord[0]) {
                bool same = true;
                for (int j = 1; j < wordLen; ++j) {
                    if (searchWord[j] != sentence[i + j]) {
                        same = false;
                        break;
                    }
                }
                if (same) return wordCount;
            }
            else check = false;
        }
        return -1;
    }
};