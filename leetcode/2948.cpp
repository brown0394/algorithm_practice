class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sortedN(nums);
        sort(sortedN.begin(), sortedN.end());
        unordered_map<int, int> groups;
        vector<list<int>> gnums;
        int groupNo = 0;
        groups[sortedN[0]] = 0;
        gnums.push_back({sortedN[0]}); 
        for (int i = 1, size = nums.size(); i < size; ++i)
        {
            if (sortedN[i] - sortedN[i-1] <= limit)
            {
                groups[sortedN[i]] = groupNo;
                gnums[groupNo].push_back(sortedN[i]);
            }
            else
            {
                groups[sortedN[i]] = ++groupNo;
                gnums.push_back({sortedN[i]}); 
            }
        }
        for (int i = 0, size = nums.size(); i < size; ++i)
        {
            groupNo = groups[nums[i]];
            nums[i] = gnums[groupNo].front();
            gnums[groupNo].pop_front();
        }
        return nums;
    }
};