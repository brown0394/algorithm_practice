class Solution {
public:
    int findTheWinner(int n, int k) {
        int carry = 0;
        for (int i = 2; i <= n; ++i) {
            carry = (carry + k) % i;
        }
        return carry + 1;
    }
};