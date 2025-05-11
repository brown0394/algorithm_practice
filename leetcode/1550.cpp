class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCount = 0;
        for (int i = 0, size = arr.size(); i < size; ++i)
        {
            if (arr[i] % 2 == 0)
            {
                oddCount = 0;
                continue;
            }
                
            ++oddCount;
            if (oddCount > 2)
                return true;
        }
        return false;
    }
};