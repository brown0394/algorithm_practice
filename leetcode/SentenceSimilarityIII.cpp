class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string *s1, *s2;
        if (sentence1.size() < sentence2.size()) {
            s1 = &sentence1;
            s2 = &sentence2;
        }
        else {
            s1 = &sentence2;
            s2 = &sentence1;
        }
        int idx1 = 0, idx2 = 0, spaceP = -1;
        int len1 = s1->size(), len2 = s2->size();
        while (idx1 < len1) {
            if ((*s1)[idx1] != (*s2)[idx2]) break;
            if ((*s1)[idx1] == ' ') {
                spaceP = idx1;
            }
            ++idx1; ++idx2;
        }
        if (idx1 == len1 && idx2 < len2 && (*s2)[idx2] == ' ') return true;
        idx1 = spaceP + 1;
        idx2 = len2 - (len1 - idx1);
        if (idx2 && (*s2)[idx2-1] != ' ') return false;
        while (idx1 < len1 && idx2 < len2) {
            if ((*s1)[idx1] != (*s2)[idx2]) return false;
            ++idx1; ++idx2;
        }
        return true;
    }
};