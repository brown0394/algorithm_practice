class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            pq.push({nums[i], i});
        }
        for (int i = 0; i < k; ++i) {
            int idx = pq.top().second;
            pq.pop();
            nums[idx] *= multiplier;
            pq.push({nums[idx], idx});
        }
        return nums;
    }
};