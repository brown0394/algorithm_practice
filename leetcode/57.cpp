class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        if (!len) return {newInterval};
        vector<vector<int>> answer;
        if (intervals[0][0] > newInterval[1]) {
            answer.push_back(newInterval);
            answer.insert(answer.end(), intervals.begin(), intervals.end());
            return answer;
        }
        if (intervals.back()[1] < newInterval[0]) {
            answer = intervals;
            answer.push_back(newInterval);
            return answer;
        }
        int i = 0;
        for (; i < len; ++i) {
            if (intervals[i][1] < newInterval[0]) {
                answer.push_back(intervals[i]);
                continue;
            }
            if (intervals[i][0] > newInterval[1]) {
                answer.push_back(newInterval);
                break;
            }
            int smaller = min(intervals[i][0], newInterval[0]);
            int bigger = max(intervals[i][1], newInterval[1]);
            answer.push_back({smaller, bigger});
            ++i;
            break;
        }
        for (; i < len && answer.back()[1] >= intervals[i][0]; ++i) {
            answer.back()[1] = max(answer.back()[1], intervals[i][1]);
        }
        for (; i < len; ++i) answer.push_back(intervals[i]);
        return answer;
    }
};