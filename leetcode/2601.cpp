class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        list<int> TwoToThousand;
        primes.push_back(2);
        for (int i = 3; i < 1000; i += 2) TwoToThousand.push_back(i);
        while (!TwoToThousand.empty()) {
            int num = *TwoToThousand.begin();
            primes.push_back(num);
            for (auto it = TwoToThousand.begin(); it != TwoToThousand.end(); ++it) {
                if (*it % num == 0) it = TwoToThousand.erase(it);
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