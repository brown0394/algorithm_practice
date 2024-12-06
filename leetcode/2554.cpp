
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int lim = min(n, maxSum);
        vector<bool> isBanned(lim+1);
        for (int i = 0, len = banned.size(); i < len; ++i) {
            if (banned[i] <= lim) isBanned[banned[i]] = true;
        }
        int count = 0, sum = 0;
        for (int i = 1; i <= lim; ++i) {
            if (!isBanned[i]) {
                if (sum + i > maxSum) return count;
                sum += i;
                ++count;
            }
        }
        return count;
    }
};