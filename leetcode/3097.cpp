class Solution {
    vector<int> bitCounts;
    void countBits(int target, int delta) {
        int bit = 1;
        int idx = 0;
        while (bit <= target) {
            if (bit & target) bitCounts[idx] += delta;
            bit <<= 1;
            ++idx;
        }
    }

    int getBit() {
        int cur = 1;
        int bit = 0;
        for (int i = 0; i < 31; ++i) {
            if (bitCounts[i]) bit |= cur;
            cur <<= 1; 
        }
        return bit;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0, right = 0;
        bitCounts.resize(31);
        int minLen = size + 1;
        int bit = 0;
        while (right < size) {
            bit |= nums[right];
            countBits(nums[right], 1);
            if (bit >= k) {
                int lbit = 0;
                do {
                    minLen = min(minLen, (right - left) + 1);
                    countBits(nums[left], -1);
                    lbit = getBit();
                    ++left;
                } while(lbit >= k && left <= right);
                bit = lbit;
            }
            ++right;
        }
        if (minLen == size + 1) return -1;
        return minLen;
    }
};