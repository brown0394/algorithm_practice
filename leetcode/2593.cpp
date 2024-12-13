class Solution {
public:
    long long findScore(vector<int>& nums) {
        int size = nums.size();
        vector<bool> marked(size);
        vector<vector<int>> numsWIdx(size, vector<int>(2));
        for (int i = 0; i < size; ++i) {
            numsWIdx[i][0] = nums[i];
            numsWIdx[i][1] = i;
        }
        sort(numsWIdx.begin(), numsWIdx.end());
        long long total = 0;
        for (int i = 0; i < size; ++i) {
            if (marked[numsWIdx[i][1]]) continue;
            marked[numsWIdx[i][1]] = true;
            total += numsWIdx[i][0];
            if (numsWIdx[i][1]) marked[numsWIdx[i][1] - 1] = true;
            if (numsWIdx[i][1] + 1 < size) marked[numsWIdx[i][1] + 1] = true;
        }
        return total;
    }
};