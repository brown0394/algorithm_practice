class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int maxIdx = max_element(height.begin(), height.end()) - height.begin();
        int trapped = 0;
        int cur = 0;
        for (int i = 0; i < maxIdx; ++i) {
            if (height[i] > cur) cur = height[i];
            else trapped += cur - height[i];
        }
        cur = 0;
        for (int i = len - 1; i > maxIdx; --i) {
            if (height[i] > cur) cur = height[i];
            else trapped += cur - height[i];
        }        
        return trapped;
    }
};