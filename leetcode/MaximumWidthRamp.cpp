class Solution {
    struct node {
        int idx;
        int val;
        bool operator < (const node& other) {
            if (val == other.val) return idx < other.idx;
            return val < other.val;
        }
    };
public:
    int maxWidthRamp(vector<int>& nums) {
        int len = nums.size();
        vector<node> infos(len);
        for (int i = 0; i < len; ++i) {
            infos[i].idx = i;
            infos[i].val = nums[i];
        }
        sort(infos.begin(), infos.end());
        int max = 0;
        int minIdx = infos[0].idx;
        for (int i = 1; i < len; ++i) {
            if (minIdx > infos[i].idx) {
                minIdx = infos[i].idx;
                continue;
            }
            if (max < infos[i].idx - minIdx) max = infos[i].idx - minIdx;
        }
        return max;
    }
};