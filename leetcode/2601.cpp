class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        bitset<1001> TwoToThousand;
        TwoToThousand[0] = true;
        TwoToThousand[1] = true;
        for (int i = 2; i <= 1000; ++i) {
            if (TwoToThousand[i]) continue;
            primes.push_back(i);
            for (int j = i + i; j <= 1000; j += i) {
                TwoToThousand[j] = true;
            }
        }
        
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i] >= nums[i + 1]) {
                auto found = lower_bound(primes.begin(), primes.end(), (nums[i] - nums[i+1]) + 1);
                if (*found >= nums[i]) return false;
                nums[i] -= *found;
                if (nums[i] >= nums[i + 1]) return false;
            }
        }
        return true;
    }
};