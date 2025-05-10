class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;
        long long zeros1 = 0;
        long long zeros2 = 0;
        for (auto it = nums1.begin(); it != nums1.end(); ++it)
        {
            if (*it > 0)
                sum1 += *it;
            else
                ++zeros1;
        }
        for (auto it = nums2.begin(); it != nums2.end(); ++it)
        {
            if (*it > 0)
                sum2 += *it;
            else
                ++zeros2;
        }
        sum1 += zeros1;
        sum2 += zeros2;
        if (sum1 > sum2 && zeros2 == 0)
            return -1;
        if (sum2 > sum1 && zeros1 == 0)
            return -1;
        return max(sum1, sum2);
    }
};