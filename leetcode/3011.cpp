class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int size = nums.size();
        vector<pair<int, int>> numsWithBits(size);
        for (int i = 0; i < size; ++i) {
            numsWithBits[i].first = nums[i];
            int bit = 1;
            for (int j = 0; j < 9; ++j) {
                if (bit & nums[i]) ++numsWithBits[i].second;
                bit <<= 1;
            }
            int idx = i;
            while (idx && numsWithBits[idx].first < numsWithBits[idx-1].first) {
                if (numsWithBits[idx].second != numsWithBits[idx-1].second) return false;
                swap(numsWithBits[idx], numsWithBits[idx-1]);
                --idx;
            }
            
        }
        return true;
    }
};