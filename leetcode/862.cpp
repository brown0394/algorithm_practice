class Solution {
    int getIdx(long long val, deque<pair<long long, int>>& dq) {
        int right = dq.size()-1;
        int left = 0;
        int idx = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (dq[mid].first > val) {
                right = mid - 1;
            }
            else {
                idx = mid;
                left = mid + 1;
            }
        }
        return idx;
    }
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const int INV = 1000000;
        int shortestLen = INV;
        int size = nums.size();
        long long cur = 0;
        deque<pair<long long, int>> dq;
        dq.emplace_back(0, -1);
        for (int i = 0; i < size; ++i) {
            cur += nums[i];
            
            while (!dq.empty() && dq.back().first >= cur) {
                dq.pop_back();
            }
            int idx = getIdx(cur - k, dq);
            if (idx >= 0) shortestLen = min(shortestLen, i - dq[idx].second);
            dq.emplace_back(cur, i);
            
        }
        if (shortestLen == INV) return -1;
        return shortestLen;
    }
};