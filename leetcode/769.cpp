class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int v = arr[0];
        int total = 0;
        for (int i = 0, len = arr.size(); i < len; ++i) {
            if (arr[i] > v) v = arr[i];
            if (v <= i) {
                ++total;
                v = 0;
            }
        }
        return total;
    }
};