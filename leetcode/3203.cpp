class Solution {
    int diameter;
    int calcDiameter(vector<vector<int>>& adjList, int cur, int parent) {
        int size = adjList[cur].size();
        int mv1 = 0, mv2 = 0;
        for (int i = 0; i < size; ++i) {
            if (adjList[cur][i] == parent) continue;
            int calcV = calcDiameter(adjList, adjList[cur][i], cur) + 1;
            if (calcV > mv1) {
                mv2 = mv1;
                mv1 = calcV;
            }
            else if (calcV > mv2) mv2 = calcV;
        }
        diameter = max(diameter, mv1 + mv2);
        return mv1;
    }
    int getDiameter(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<vector<int>> adjList(size+1);
        diameter = 0;
        for (int i = 0; i < size; ++i) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        int calcV = calcDiameter(adjList, 0, 0);
        return max(diameter, calcV);
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int v1 = getDiameter(edges1);
        int v2 = getDiameter(edges2);
        int v3 = ceil(v1 / 2.0f) + ceil(v2 / 2.0f) + 1;
        int t = max(v1, v2);
        return max(t, v3);
    }
};