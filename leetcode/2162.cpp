class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int less = 0, greater = ans.size()-1;
        for (int i = 0, j = greater; i < nums.size(); ++i, --j)
        {
            if (nums[i] < pivot)
                ans[less++] = nums[i];
            if (nums[j] > pivot)
                ans[greater--] = nums[j];
        }
        while (less <= greater) ans[less++] = pivot;
        return ans;
    }
};