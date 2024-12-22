class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        stack<int> stk;
        int size = heights.size();
        vector<int> nextIdx(size, -1);
        stk.push(0);
        for (int i = 1; i < size; ++i) {
            while (!stk.empty() && heights[stk.top()] < heights[i]) {
                nextIdx[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        size = queries.size();
        vector<int> ans(size);
        for (int i = 0; i < size; ++i) {
            if (queries[i][0] == queries[i][1]) {
                ans[i] = queries[i][0];
                continue;
            }
            if (queries[i][0] > queries[i][1]) swap(queries[i][0], queries[i][1]);
            if (heights[queries[i][1]] > heights[queries[i][0]]) {
                ans[i] = queries[i][1];
            }
            else if (heights[queries[i][1]] == heights[queries[i][0]]) {
                ans[i] = nextIdx[queries[i][1]];
            }
            else {
                if (nextIdx[queries[i][0]] < 0 || nextIdx[queries[i][1]] < 0) {
                    ans[i] = -1;
                    continue;
                }
                if (nextIdx[queries[i][0]] >= nextIdx[queries[i][1]]) {
                    ans[i] = nextIdx[queries[i][0]];
                    continue;
                }
                int next = nextIdx[queries[i][1]];
                while (next > 0 && heights[next] < heights[queries[i][0]]) {
                    next = nextIdx[next];
                }
                if (next == -1) ans[i] = -1;
                else ans[i] = next;
            }
        }
        return ans;
    }
};