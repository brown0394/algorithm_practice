class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<int> parent(size + 1);
        for (int i = 0; i < size; ++i) 
        {
            if (parent[edges[i][0]] == 0)
            {
                parent[edges[i][0]] = edges[i][1];
                if (parent[edges[i][1]] == 0)
                    parent[edges[i][1]] = edges[i][1];
            }
            else
            {
                if (parent[edges[i][1]] == 0)
                    parent[edges[i][1]] = edges[i][0];
                else
                {
                    int p1 = edges[i][0];
                    while (parent[p1] != p1)
                        p1 = parent[p1];
                    int p2 = edges[i][1];
                    while (parent[p2] != p2)
                        p2 = parent[p2];
                    
                    if (p1 == p2)
                        return {edges[i][0], edges[i][1]};
                    parent[p2] = edges[i][0];
                }
            }
        }
        return {};
    }
};