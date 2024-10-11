class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int, vector<int>, greater<int>> chairs;
        int lastChair = 0;
        int targetEnter = times[targetFriend][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavings;
        sort(times.begin(), times.end(), [](vector<int>& one, vector<int>& two) {
            return one[0] < two[0];
        });
        for (vector<int>& val : times) {
            while (!leavings.empty() && leavings.top().first <= val[0]) {
                chairs.push(leavings.top().second);
                leavings.pop();
            }
            int chair = 0;
            if (chairs.empty()) {
                chair = lastChair++;
            }
            else {
                chair = chairs.top();
                chairs.pop();
            }
            if (val[0] == targetEnter) return chair;
            if (val[1] <= targetEnter) {
                leavings.push({val[1], chair});
            }
        }
        return 0;
    }
};