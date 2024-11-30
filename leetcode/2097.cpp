class Solution {
    unordered_map<int, deque<int>> pairmap;
    vector<int> visitSeq;
    void visit(int n) {
        while (!pairmap[n].empty()) {
            int next = pairmap[n].front();
            pairmap[n].pop_front();
            visit(next);
        }
        visitSeq.push_back(n);
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> inbounds;
        int numOfPairs = pairs.size();
        for (int i = 0; i < numOfPairs; ++i) {
            pairmap[pairs[i][0]].push_back(pairs[i][1]);
            ++inbounds[pairs[i][1]];
        }

        int start = pairmap.begin()->first;
        for (auto& p : pairmap) {
            if (inbounds[p.first] < p.second.size()) {
                start = p.first;
                break;
            }
        }
        visit(start);
        vector<vector<int>> answer;
        for (int i = visitSeq.size()-2; i >= 0; --i) {
            answer.push_back({visitSeq[i+1], visitSeq[i]});
        }
        return answer;
    }
};