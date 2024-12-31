class Solution {

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int cur = 0;
        int size = days.size();
        vector<int> memo(size+1, 1000000000);
        memo[0] = 0;
        auto found = lower_bound(days.begin(), days.end(), days[0] + 7);
        int weekLater = size;
        if (found != days.end()) weekLater = found - days.begin();
        found = lower_bound(days.begin(), days.end(), days[0] + 30);
        int monthLater = size;
        if (found != days.end()) monthLater = found - days.begin();
        for (int i = 0; i < size; ++i) {
            memo[i+1] = min(memo[i+1], memo[i] + costs[0]);
            while(weekLater < size && days[weekLater] - days[i] < 7) ++weekLater;
            while(monthLater < size && days[monthLater] - days[i] < 30) ++monthLater;
            memo[weekLater] = min(memo[weekLater], memo[i] + costs[1]);
            memo[monthLater] = min(memo[monthLater], memo[i] + costs[2]);
        }
        return memo[size];
    }
};