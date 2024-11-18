class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const int INV = 1000000;
        int shortestLen = INV;
        int size = nums.size();
        vector<long long> prefixSums(size + 1);
        for (int i = 1; i <= size; ++i) {
            prefixSums[i] = prefixSums[i-1] + nums[i-1];
        }
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i <= size; ++i) {
            while (!dq.empty() && prefixSums[i] - prefixSums[dq.front()] >= k) {
                shortestLen = min(shortestLen, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefixSums[dq.back()] >= prefixSums[i]) dq.pop_back();
            dq.emplace_back(i);
        }
        if (shortestLen == INV) return -1;
        return shortestLen;
    }
};