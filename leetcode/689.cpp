class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> subarrays(nums.size() - (k-1));
        int cur = 0;
        for (int i = 0; i < k; ++i) cur += nums[i];
        subarrays[0] = cur;
        for (int i = k; i < nums.size(); ++i) {
            cur = cur - nums[i-k] + nums[i];
            subarrays[i-k+1] = cur;
        }
        vector<pair<int, int>> possibleOnes(nums.size() - (k*2) - (k-1));
        int thirdIdx = subarrays.size()-1;
        int secondIdx = thirdIdx - k;
        int third = thirdIdx;
        int last = subarrays[thirdIdx] + subarrays[secondIdx];
        possibleOnes.back().first = secondIdx--;
        possibleOnes.back().second = thirdIdx--;
        for (int i = possibleOnes.size()-2; i >= 0; --i) {
            if (subarrays[third] <= subarrays[thirdIdx]) {
                third = thirdIdx;
            }
            if (subarrays[secondIdx] + subarrays[third] >= last) {
                last = subarrays[secondIdx] + subarrays[third];
                possibleOnes[i].first = secondIdx;
                possibleOnes[i].second = third;
            }
            else possibleOnes[i] = possibleOnes[i+1];
            --secondIdx;
            --thirdIdx;
        }
        last = subarrays[0] + subarrays[possibleOnes[0].first] + subarrays[possibleOnes[0].second];
        vector<int> ans{0, possibleOnes[0].first, possibleOnes[0].second};
        for (int i = 1; i < possibleOnes.size(); ++i) {
            cur = subarrays[i] + subarrays[possibleOnes[i].first] + subarrays[possibleOnes[i].second];
            if (last < cur) {
                last = cur;
                ans[0] = i;
                ans[1] = possibleOnes[i].first;
                ans[2] = possibleOnes[i].second;
            }
        }
        return ans;
    }
};