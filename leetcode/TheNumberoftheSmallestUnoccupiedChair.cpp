class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int> chairs;
        int lastChair = 0;
        int targetEnter = times[targetFriend][0];
        vector<vector<int>> leavings(targetEnter+1);
        sort(times.begin(), times.end(), [](vector<int>& one, vector<int>& two) {
            return one[0] < two[0];
        });
        int timesChecked = 0;
        for (vector<int>& val : times) {
            for (; timesChecked <= val[0]; ++timesChecked) {
                for (int chairReturned : leavings[timesChecked]) {
                    chairs.insert(chairReturned);
                }
            }
            int chair = 0;
            if (chairs.empty()) {
                chair = lastChair++;
            }
            else {
                chair = *chairs.begin();
                chairs.erase(chairs.begin());
            }
            if (val[0] == targetEnter) return chair;
            if (val[1] <= targetEnter) {
                leavings[val[1]].push_back(chair);
            }
        }
        return 0;
    }
};