class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numSize = nums.size();
        int zeroIdx = 0;
        int twoIdx = numSize-1;

        int i = 0;
        while ( i <= twoIdx )
        {
            if (nums[i] == 1)
                ++i;
            else if (nums[i] == 0)
            {
                if ( zeroIdx == i )
                {
                    ++i;
                    continue;
                }
                swap(nums[i], nums[zeroIdx]);
                ++zeroIdx;
            }
            else
            {
                swap(nums[i], nums[twoIdx]);
                --twoIdx;
            }
        }
    }
};