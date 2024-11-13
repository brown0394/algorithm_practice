class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int mul = nums.size();
        int til = 1;
        while (mul > 1) {
            til *= mul--;
        }
        for (int i = 0; i < til; ++i) {
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
    }
};