class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longestSeq = 1;
        for (int i = 0, len = nums.size(); i < len - longestSeq; ++i) {
            int seq = 0;
            int square = nums[i];
            auto next = nums.begin() + i;
            do {
                ++seq;
                if (*next > 46340) break;
                square = *next * (*next);
                next = lower_bound(next, nums.end(), square);
            } while (next != nums.end() && *next == square);
            if (seq > longestSeq) longestSeq = seq;
        }
        if (longestSeq == 1) return -1;
        return longestSeq;
    }
};