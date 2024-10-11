class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int len = nums.size();
        stack<int> idxStack;
        idxStack.push(0);
        for (int i = 1; i < len-1; ++i) {
            if(nums[i] < nums[idxStack.top()]) idxStack.push(i);
        }
        int idx = len - 1;
        int maxWidth = 0;
        while (!idxStack.empty()) {
            if (nums[idx] >= nums[idxStack.top()]) {
                if (maxWidth < idx - idxStack.top()) {
                    maxWidth = idx - idxStack.top();
                }
                idxStack.pop();
            }
            else --idx;
        }
        return maxWidth;
    }
};