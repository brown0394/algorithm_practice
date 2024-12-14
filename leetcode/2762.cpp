class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int size = nums.size();
        long long total = 0;
        int left = 0, right = 0;
        map<int, int> counts;
        while (right < size) {
            auto found = counts.find(nums[right]);
            if (found == counts.end()) counts.insert({nums[right], 1});
            else ++found->second;
            while (!counts.empty() && abs(counts.begin()->first - counts.rbegin()->first) > 2)
            {
                found = counts.find(nums[left]);
                if (found->second > 1) --found->second;
                else counts.erase(found);
                ++left;
            }
            if (left <= right) {
                long long n = right - left + 1;
                total += n;
            }
            ++right;
        }
        return total;
    }
};