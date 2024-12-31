class Solution {
    int size;
    vector<int> memo;
    int includedDays[2];
    void plan(vector<int>& days, vector<int>& costs, int idx, int cost) {
        if (memo[idx] < cost) return;
        memo[idx] = cost;
        if (idx == size) return;
        
        for (int i = 0; i < 2; ++i) {
            auto found = lower_bound(days.begin()+idx, days.end(), days[idx] + includedDays[i]);
            int next = size;
            if (found != days.end()) next = found - days.begin();
            plan(days, costs, next, cost + costs[2-i]);
        }
        plan(days, costs, idx+1, cost + costs[0]);
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int cur = 0;
        size = days.size();
        memo.resize(size+1, 1000000000);
        includedDays[0] = 30;
        includedDays[1] = 7;
        plan(days, costs, 0, 0);
        return memo[size];
    }
};