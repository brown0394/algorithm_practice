class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size = nums.size();
        vector<int> longestSeq;
        longestSeq.push_back(nums[0]);
        vector<vector<int>> increasingSeqCounts(2, vector<int>(size));
        int left = 0, right = size-1;
        for (int i = 1; i < size; ++i) {
            if (longestSeq.back() < nums[i]) {
                longestSeq.push_back(nums[i]);
                increasingSeqCounts[0][i] = increasingSeqCounts[0][i-1] + 1;
                left = i;
            }
            else {
                increasingSeqCounts[0][i] = increasingSeqCounts[0][i - 1];
                *(lower_bound(longestSeq.begin(), longestSeq.end(), nums[i])) = nums[i];
            }
        }
        longestSeq.clear();
        longestSeq.push_back(nums[size-1]);
        for (int i = size - 2; i >= 0; --i) {
            if (longestSeq.back() < nums[i]) {
                longestSeq.push_back(nums[i]);
                increasingSeqCounts[1][i] = increasingSeqCounts[1][i+1] + 1;
                right = i;
            }
            else {
                increasingSeqCounts[1][i] = increasingSeqCounts[1][i + 1];
                *(lower_bound(longestSeq.begin(), longestSeq.end(), nums[i])) = nums[i];
            }
        }
        int maxAmount = 0;
        if (left > right) swap(left, right);
        for (int i = left; i <= right; ++i) {
            if (!increasingSeqCounts[0][i]) continue;
            else if (!increasingSeqCounts[1][i]) break;
            maxAmount = max(maxAmount, increasingSeqCounts[0][i] + increasingSeqCounts[1][i]);
        }
        return size - maxAmount - 1;
    }
};