class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int len = nums.size();
        deque<int> biggestValIdx;
        biggestValIdx.push_back(len - 1);
        for (int i = len - 2; i >= 0; --i) {
            if (nums[i] > nums[biggestValIdx.front()]) biggestValIdx.push_front(i);
        }
        int left = 0;
        int maxWidth = biggestValIdx.front();
        int right = 0;
        len = biggestValIdx.size();
        while (right < len) {
            while (left <= biggestValIdx[right] && nums[left] > nums[biggestValIdx[right]]) ++left;
            while (right < len - 1) {
                if (nums[biggestValIdx[right + 1]] >= nums[left]) ++right;
                else break;
            }
            maxWidth = max(maxWidth, biggestValIdx[right] - left);
            ++left;
            ++right;
        }
        return maxWidth;
    }
};