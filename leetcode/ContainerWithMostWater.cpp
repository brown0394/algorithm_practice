class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int water = right - left;
            if (height[left] > height[right]) water *= height[right--];
            else water *= height[left++];
            if (water > max) max = water;
        }
        return max;
    }
};