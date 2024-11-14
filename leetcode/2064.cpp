class Solution {
    bool validityCheck(int n, vector<int>& quantities, int val) {
        if (val == 0) return false;
        for (int i = 0, len = quantities.size(); i < len; ++i) {
            n -= (quantities[i] / val);
            if (quantities[i] % val) --n;
            if (n < 0) return false;
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long sum = 0;
        int len = quantities.size();
        int high = 0;
        for (int i = 0; i < len; ++i) {
            sum += quantities[i];
            high = max(high, quantities[i]);
        }
        int low = sum / n;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (validityCheck(n, quantities, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};