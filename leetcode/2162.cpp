class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        vector<int> pivots;
        vector<int> greaters;

        for (int n : nums)
        {
            if (n == pivot)
                pivots.push_back(pivot);
            else if (n < pivot)
                ans.push_back(n);
            else
                greaters.push_back(n);
        }
        copy(pivots.begin(), pivots.end(), back_inserter(ans));
        copy(greaters.begin(), greaters.end(), back_inserter(ans));
        return ans;
    }
};