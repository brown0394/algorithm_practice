class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        int size = nums.size();
        unordered_map<int, int> countMap;
        for (int i = 0; i < size; ++i)
        {
            int cur = i - nums[i];
            count += (i - countMap[cur]);
            ++countMap[cur];
        }
        return count;
    }
};