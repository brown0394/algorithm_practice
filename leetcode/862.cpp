class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const int INV = 1000000;
        int shortestLen = INV;
        int size = nums.size();
        if (size == 1) {
            if (nums[0] >= k) return 1;
            else return -1;
        }
        long long cur = nums[0];
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({nums[0], 0});
        for (int i = 1; i < size; ++i) {
            cur += nums[i];
            if (cur >= k) shortestLen = min(shortestLen, i + 1);
            while (!pq.empty() && cur - pq.top().first >= k) {
                shortestLen = min(shortestLen, i - pq.top().second);
                pq.pop();
            }
            pq.push({cur, i});
        }
        if (shortestLen == INV) return -1;
        return shortestLen;
    }
};