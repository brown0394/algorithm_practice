class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<pair<int, int>> heightSorted(len);
        for (int i = 0; i < len; ++i) {
            heightSorted[i].first = height[i];
            heightSorted[i].second = i;
        }
        sort(heightSorted.begin(), heightSorted.end(), greater<pair<int, int>>());
        int left = heightSorted[0].second;
        int right = left;
        int i = 1;
        int trapped = 0;
        while (i < len) {
            while (i < len && heightSorted[i-1] == heightSorted[i]) {
                ++i;
            }
            if (heightSorted[i-1].second < left) {
                for (int j = left - 1; j > heightSorted[i-1].second; --j) {
                    trapped += heightSorted[i-1].first - height[j];
                }
                left = heightSorted[i-1].second;
            }
            if (i == len) break;
            if (heightSorted[i].second > right) {
                for (int j = right + 1; j < heightSorted[i].second; ++j) {
                    trapped += heightSorted[i].first - height[j];
                }
                right = heightSorted[i].second;
            }
            ++i;
        }
        return trapped;
    }
};