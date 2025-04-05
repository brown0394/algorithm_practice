class Solution {
    int subSum(vector<int>& nums, int idx, int x)
    {
        if (idx == nums.size())
            return 0;
        int sum = 0;
        for (int i = idx; i < nums.size(); ++i)
        {
            sum += x ^ nums[i];
            sum += subSum(nums, i + 1, x ^ nums[i]);
        }
        return sum;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            sum += subSum(nums, i + 1, nums[i]);
        }
        return sum;
    }
};