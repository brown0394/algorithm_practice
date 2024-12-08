class Solution {
    static bool compare(int value, vector<int>& two) {
        return value < two[0];
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int size = events.size();
        sort(events.begin(), events.end());
        vector<int> maxVs(size);
        maxVs[size-1] = events[size-1][2];
        for (int i = size-2; i > 0; --i) {
            maxVs[i] = max(maxVs[i+1], events[i][2]);
        }
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            int next = upper_bound(events.begin()+i+1, events.end(), events[i][1], compare) - events.begin();
            if (next == size) ans = max(ans, events[i][2]);
            else ans = max(ans, events[i][2] + maxVs[next]);
        }
        return ans;
    }
};