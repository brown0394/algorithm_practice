class Solution {
public:
    struct info {
        int val, idx;
        bool operator < (const info& other) {
            if (val == other.val) return idx < other.idx;
            return val < other.val;
        }
    };
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<info> infos(nums.size());
        for (int i = 0, len = nums.size(); i < len; ++i) {
            infos[i].idx = i;
            infos[i].val = nums[i];
        }
        std::sort(infos.begin(), infos.end());
        int start = 0, end = infos.size()-1;
        while (start < end) {
            int calc = infos[start].val + infos[end].val;
            if (calc == target) {
                return {infos[start].idx, infos[end].idx};
            }
            if (calc < target) {
                ++start;
            }
            else --end;
        }
        return {};
    }
};