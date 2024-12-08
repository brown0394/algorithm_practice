class Solution {
    vector<vector<int>> memo;
    int size;
    static bool compare(int value, vector<int>& two) {
        return value < two[0];
    }
    int check(vector<vector<int>>& events, int idx) {
        int next = upper_bound(events.begin()+idx, events.end(), events[idx][1], compare) - events.begin();
        if (next == size) {
            return events[idx][2];
        }
        int maxV = 0;
        for (; next < size; ++next) {
            if (memo[idx][next] == -1) {
                memo[idx][next] = check(events, next) + events[idx][2];
            }
            maxV = max(maxV, memo[idx][next]);
        }
        return maxV;
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        size = events.size();
        memo.resize(size, vector<int>(size, -1));
        sort(events.begin(), events.end());
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            ans = max(ans, check(events, i));
        }
        return ans;
    }
};