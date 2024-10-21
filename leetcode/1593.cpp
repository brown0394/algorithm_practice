class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> strSet;
        strLen = s.size();
        maxPossible = 0;
        searchCombinations(strSet, s, 0, 0);
        return maxPossible;
    }
private:
    int maxPossible;
    int strLen;
    void searchCombinations(unordered_set<string>& strSet, string& s, int count, int idx) {
        if (idx == strLen) {
            if (maxPossible < count) maxPossible = count;
            return;
        }
        string curStr = "";
        for (; idx < strLen; ++idx) {
            if (count + (strLen - idx) <= maxPossible) break;
            if (count + 26 <= maxPossible) break;
            curStr.push_back(s[idx]);
            if (strSet.find(curStr) == strSet.end()) {
                auto loc = strSet.insert(curStr).first;
                searchCombinations(strSet, s, count + 1, idx + 1);
                strSet.erase(loc);
            }
        }
    }
};