#include <iostream>
#include <vector>
class Solution {
public:
    static double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        int mid = size >> 1;
        bool isOdd = size % 2;
        if (!isOdd) --mid;
        int idx = 0, idx1 = 0, idx2 = 0;
        double median = 0.0f;
        while (idx <= mid) {
            int cur = 0;
            if (idx1 < size1 && idx2 < size2) {
                if (nums1[idx1] <= nums2[idx2]) {
                    cur = nums1[idx1++];
                }
                else cur = nums2[idx2++];
            }
            else if (idx1 < size1) cur = nums1[idx1++];
            else cur = nums2[idx2++];
            if (idx++ == mid) {
                if (isOdd) return cur;
                if (!median) ++mid;
                median += cur;
            }
        }
        return median / 2.0f;
    }
};

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::vector<int> one{ 0,0 };
	std::vector<int> two{ 0,0 };
	std::cout << Solution::findMedianSortedArrays(one, two) << '\n';
	
}