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
        int idx = k;
        possibleOnes[0].first = idx++;
        for (int i = 1; i < possibleOnes.size(); ++i) {
            if (subarrays[possibleOnes[i-1].first] < subarrays[idx]) {
                possibleOnes[i].first = idx;
            }
            else possibleOnes[i].first = possibleOnes[i-1].first;
            ++idx;
        }
        idx = subarrays.size()-k;
        possibleOnes.back().second = idx--;
        for (int i = possibleOnes.size()-2; i >= 0; --i) {
            if (subarrays[possibleOnes[i+1].second] < subarrays[idx]) {
                possibleOnes[i].second = idx;
            }
            else possibleOnes[i].second = possibleOnes[i+1].second;
            ++idx;
        }
        for (auto& p : possibleOnes) cout << p.first << " " << p.second << endl;
        return subarrays;
    }
};