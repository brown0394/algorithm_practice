class Solution {
    int size;
    bool possible(long long time, vector<int>& ranks, int cars)
    {
        for (int i = 0; i < size; ++i)
        {
            long long divided = time / ranks[i];
            if (divided < 1)
                return false;
            long long carsRepaired = sqrt(divided);
            if (carsRepaired == 0)
                return false;
            cars -= carsRepaired;
            if (cars <= 0)
                return true;
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        size = ranks.size();

        long long maxTime = static_cast<long long>(ranks.back()) * cars * cars;
        long long minTime = 1;
        long long ans = maxTime;
        while (minTime <= maxTime)
        {
            long long mid = (minTime + maxTime) >> 1;
            if (possible(mid, ranks, cars) == true)
            {
                maxTime = mid - 1;
                ans = mid;
            }
            else
                minTime = mid + 1;
        }
        return ans;
    }
};