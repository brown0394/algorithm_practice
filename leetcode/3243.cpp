class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> distances(n, n);
        distances[n - 1] = 0;
        vector<vector<int>> connections(n);
        for (int i = 0; i < n; ++i) {
            distances[n - 1 - i] = i;
            if (i) connections[i].push_back(i - 1);
        }
        vector<int> answer;
        for (int i = 0, len = queries.size(); i < len; ++i) {
            connections[queries[i][1]].push_back(queries[i][0]);
            if (distances[queries[i][0]] <= distances[queries[i][1]] + 1) {
                answer.push_back(distances[0]);
                continue;
            }
            distances[queries[i][0]] = distances[queries[i][1]] + 1;
            for (int j = queries[i][0]; j >= 0; --j) {
                for (int k = 0, size = connections[j].size(); k < size; ++k) {
                    distances[connections[j][k]] = min(distances[connections[j][k]], distances[j] + 1);
                }
            }
            answer.push_back(distances[0]);
        }
        return answer;
    }
};