class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int idx1 = 0, idx2 = 0;
        int size1 = nums1.size(), size2 = nums2.size();

        vector<vector<int>> ans;
        while (idx1 < size1 && idx2 < size2)
        {
            if (nums1[idx1][0] == nums2[idx2][0])
            {
                ans.push_back({nums1[idx1][0], nums1[idx1][1] + nums2[idx2][1]});
                ++idx1;
                ++idx2;
            }
            else if (nums1[idx1][0] < nums2[idx2][0])
                ans.push_back(nums1[idx1++]);
            else
                ans.push_back(nums2[idx2++]);
        }
        while (idx1 < size1)
        {
            ans.push_back(nums1[idx1++]);
        }
        while (idx2 < size2)
        {
            ans.push_back(nums2[idx2++]);
        }
        return ans;
    }
};