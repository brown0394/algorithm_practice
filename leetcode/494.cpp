class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        unordered_map<int, int>* cur = &m1;
        unordered_map<int, int>* next = &m2;
        ++(*cur)[nums[0]];
        ++(*cur)[-nums[0]];
        for (int i = 1, size = nums.size(); i < size; ++i) {
            auto it = cur->begin();
            while(!cur->empty()) {
                (*next)[it->first + nums[i]] += it->second;
                (*next)[it->first - nums[i]] += it->second;
                it = cur->erase(it);
            }
            swap(cur, next);
        }
        auto found = cur->find(target);
        if (found == cur->end()) return 0;
        return found->second;
    }
};