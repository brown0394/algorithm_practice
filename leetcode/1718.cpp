class Solution {
    vector<int> ans;
    vector<bool> nums;
    int size;
    bool build(int idx)
    {
        if (idx == size)
            return true;
        while (idx < size && ans[idx] > 0) ++idx;
        if (idx == size)
            return true;
        for (int i = nums.size() - 1; i >= 1; --i)
        {
            if (i == 1)
            {
                if (nums[i] == true)
                    return false;
                nums[i] = true;
                ans[idx] = 1;
                if (build(idx + 1) == true)
                    return true;
                ans[idx] = 0;
                nums[i] = false;
                return false;
            }
            if (nums[i] == true || idx + i >= size || ans[idx + i] > 0)
                continue;
            nums[i] = true;
            ans[idx] = i;
            ans[idx + i] = i;
            if (build(idx + 1) == true)
                return true;
            ans[idx] = 0;
            ans[idx + i] = 0;
            nums[i] = false;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        size = (n << 1) - 1;
        ans.resize(size, 0);
        nums.resize(n + 1);
        build(0);
        return ans;
    }
};