class Solution {
public:
    bool check(vector<int>& nums) {
        bool checkPoint = false;
        int startVal = nums[0];
        for (int i = 1, size = nums.size(); i < size; ++i)
        {
            if (nums[i] >= nums[i-1])
            {
                if (checkPoint == true && nums[i] > startVal)
                    return false;
                continue;
            }
            if (checkPoint == true || nums[i] > startVal)
                return false;
            checkPoint = true;
        }
        return true;
    }
};