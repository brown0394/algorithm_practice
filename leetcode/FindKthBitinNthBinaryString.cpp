class Solution {
public:
    char findKthBit(int n, int k) {
        int len = (1 << n) - 1;
        bool inverted = false;
        while (len > 1) {
            int mid = (len >> 1) + 1;
            if (k == mid) {
                if (inverted) return '0';
                else return '1';
            }
            if (k > mid) {
                inverted = !inverted;
                k = mid - (k - mid);
            }
            len = len >> 1;
        }
        if (inverted) return '1';
        return '0';
    }
};