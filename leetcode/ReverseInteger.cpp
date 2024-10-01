class Solution {
public:
    int reverse(int x) {
        int newVal = 0;
        int overLimit = numeric_limits<int>::max() / 10;
        int underLimit = numeric_limits<int>::min() / 10;
        while (x) {
            if (newVal > overLimit || newVal < underLimit) return 0;
            newVal *= 10;
            newVal += x % 10;
            x /= 10;
        }
        return newVal;
    }
};