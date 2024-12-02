class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        if (!len) return {newInterval};
        vector<vector<int>> answer;
        int i = 0;
        for (; i < len && intervals[i][1] < newInterval[0]; ++i) {
            answer.push_back(intervals[i]);
        }
        if (i < len && newInterval[1] >= intervals[i][0]) {
            int smaller = min(intervals[i][0], newInterval[0]);
            int bigger = max(intervals[i][1], newInterval[1]);
            answer.push_back({smaller, bigger});
        }
        else answer.push_back(newInterval);
        for (; i < len && answer.back()[1] >= intervals[i][0]; ++i) {
            answer.back()[1] = max(answer.back()[1], intervals[i][1]);
        }
        for (; i < len; ++i) answer.push_back(intervals[i]);
        return answer;
    }
};