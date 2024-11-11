class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        bitset<1001> TwoToThousand;
        TwoToThousand[1] = true;
        for (int i = 2; i <= 1000; ++i) {
            if (TwoToThousand[i]) continue;
            for (int j = i + i; j <= 1000; j += i) {
                TwoToThousand[j] = true;
            }
        }
        int cur = 1;
        for (int i = 0, size = nums.size(); i < size; ++i) {
            while (true) {
                int diff = nums[i] - cur;
                ++cur;
                if (diff < 0) return false;
                if (!TwoToThousand[diff]) break;
            }
        }
        return true;
    }
};