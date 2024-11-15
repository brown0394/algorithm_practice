class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int i = 0;
        int size = arr.size();
        for (; i < size-1; ++i) {
            if (arr[i + 1] < arr[i]) {
                break;
            }
        }
        if (i == size-1) return 0;
        int j = size-1;
        for (; j > 0; --j) {
            if (arr[j - 1] > arr[j]) {
                break;
            }
        }
        cout << i << " " << j << '\n';
        if (arr[i] <= arr[j]) {
            return j - i - 1;
        }
        int dist = size;
        if (j == i + 1) {
            if (i + 1 < size - j) dist = i + 1;
            dist = size - j;
        }
        if (j == size - 1) {
            dist = size - i - 1;
        }
        else {
            if (i + 1 < size - j) dist = size - (size - j);
            else dist = size - (i + 1);
        }
        for (; i >= 0; --i) {
            auto found = lower_bound(arr.begin() + j, arr.end(), arr[i]);
            if (found == arr.end()) continue;
            if (dist >= found - (arr.begin() + i) - 1) dist = found - (arr.begin() + i) - 1;
            else break;
        }
        if (dist == size) {
            return size - 1;
        }
        return dist;
    }
};