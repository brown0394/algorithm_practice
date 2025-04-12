class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> arr(nums.size());
        int biggest = nums[0];
        for (int i = 1; i < nums.size()-1; ++i)
        {
            arr[i] = biggest - nums[i];
            if (arr[i] < arr[i-1])
                arr[i] = arr[i-1];
            if (biggest < nums[i])
                biggest = nums[i];
        }
        long long ans = 0;
        for (int i = nums.size()-1; i > 0; --i)
        {
            long long calc = (long long)arr[i-1] * (long long)nums[i];
            if (calc > ans)
                ans = calc;
        }
        return ans;
    }
};