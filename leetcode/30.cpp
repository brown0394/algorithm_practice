class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordSize = words[0].size();
        int wordsAmount = words.size();
        int spaceNeeded = wordsAmount * wordSize;
        vector<int> wordsNeeded, answer;
        unordered_map<string, int> wordsCount;
        for (int i = 0; i < wordsAmount; ++i) {
            auto found = wordsCount.find(words[i]);
            if (found == wordsCount.end()) {
                wordsCount.insert({ words[i], wordsNeeded.size() });
                wordsNeeded.push_back(1);
            }
            else ++wordsNeeded[found->second];
        }
        vector<int> wordsCompared(wordsNeeded.size());
        unordered_map<string, int>::iterator end = wordsCount.end();
        int len = s.size();
        for (int i = 0; i < wordSize; ++i) {
            queue<int> q;
            fill(wordsCompared.begin(), wordsCompared.end(), 0);
            unordered_map<string, int>::iterator found;
            int j = i;
            while (j <= len - wordSize) {
                found = wordsCount.find(s.substr(j, wordSize));
                if (found == end) {
                    while (!q.empty()) {
                        --wordsCompared[q.front()];
                        q.pop();
                    }
                    j += wordSize;
                    if (j > len - spaceNeeded) break;
                    continue;
                }
                if (wordsCompared[found->second] == wordsNeeded[found->second]) {
                    if (q.front() == found->second) {
                        --wordsCompared[found->second];
                        q.pop();
                    }
                    else {
                        while (wordsCompared[found->second] == wordsNeeded[found->second]) {
                            --wordsCompared[q.front()];
                            q.pop();
                            
                        }
                        if (j > len - (spaceNeeded - (wordSize * q.size()))) break;
                    }
                }
                ++wordsCompared[found->second];
                q.push(found->second);
                if (q.size() == wordsAmount) {
                    answer.push_back(j - (wordSize * (wordsAmount - 1)));
                    --wordsCompared[q.front()];
                    q.pop();
                }
                j += wordSize;
            }
        }
        return answer;
    }
};