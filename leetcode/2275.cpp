class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int bits[24]{0};
        int maxComb = 0;
        for (int i = 0, len = candidates.size(); i < len; ++i) {
            int bit = 1;
            for (int j = 0; j < 24; ++j) {
                if (bit & candidates[i]) {
                    ++bits[j];
                }
                bit <<= 1;
            }
        }
        for (int i = 0; i < 24; ++i) {
            maxComb = max(maxComb, bits[i]);
        }
        return maxComb;
    }
};