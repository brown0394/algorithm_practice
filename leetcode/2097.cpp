class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> bounds;
        unordered_map<int, deque<int>> pairmap;
        vector<int> visitSeq;
        int numOfPairs = pairs.size();
        for (int i = 0; i < numOfPairs; ++i) {
            pairmap[pairs[i][0]].push_back(pairs[i][1]);
            ++bounds[pairs[i][0]];
            --bounds[pairs[i][1]];
        }

        int start = pairmap.begin()->first;
        for (auto& p : bounds) {
            if (p.second == 1) {
                start = p.first;
                break;
            }
        }
        stack<int> stk;
        stk.push(start);
        while (!stk.empty()) {
            start = stk.top();
            if (pairmap[start].empty()) {
                visitSeq.push_back(start);
                stk.pop();
                continue;
            }
            stk.push(pairmap[start].back());
            pairmap[start].pop_back();
        }
        vector<vector<int>> answer;
        for (int i = visitSeq.size()-2; i >= 0; --i) {
            answer.push_back({visitSeq[i+1], visitSeq[i]});
        }
        return answer;
    }
};