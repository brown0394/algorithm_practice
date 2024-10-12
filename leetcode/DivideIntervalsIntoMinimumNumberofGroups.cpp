class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& one, vector<int>& two) {
            if (one[0] == two[0]) return (one[1] - one[0] < two[1] - two[0]);
            return one[0] < two[0];
        });
        map<int, int> groups;
        int totGroups = 0;
        for (int i = 0, len = intervals.size(); i < len; ++i) {
            auto found = groups.lower_bound(intervals[i][0]);
            if (found != groups.begin()) {
                --found;
                if (found->second > 1) --found->second;
                else groups.erase(found);
                --totGroups;
            }
            found = groups.lower_bound(intervals[i][1]);
            if (found != groups.end() && found->first == intervals[i][1]) ++found->second;
            else groups.emplace_hint(found, intervals[i][1], 1);
            ++totGroups;
        }
        return totGroups;
    }
};