class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int lowest = numeric_limits<int>::max();
        int highest = 0;
        for (vector<int>& interval : intervals) {
            if (interval[0] < lowest) lowest = interval[0];
            if (interval[0] > highest) highest = interval[0];
        }
        vector<int> overlaps((highest - lowest) + 2);
        highest = overlaps.size();
        for (vector<int>& interval : intervals) {
            ++overlaps[interval[0] - lowest];
            if (interval[1] + 1 - lowest < highest) {
                --overlaps[interval[1] + 1 - lowest];
            }
            
        }
        int minGroupsNeeded = 0;
        int overlapCount = 0;
        for (int val : overlaps) {
            overlapCount += val;
            if (overlapCount > minGroupsNeeded) minGroupsNeeded = overlapCount;
        }
        return minGroupsNeeded;
    }
};