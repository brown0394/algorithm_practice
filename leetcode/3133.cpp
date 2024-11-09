class Solution {
public:
    long long minEnd(int n, int x) {
        long long last = x;
        for (int i = 1; i < n; ++i) {
            ++last;
            last |= x;
        }
        return last;
    }
};