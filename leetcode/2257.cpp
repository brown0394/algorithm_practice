class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int guarded = (m * n) - guards.size() - walls.size();
        vector<vector<int>> onSight(m, vector<int>(n));
        for (int i = 0, len = walls.size(); i < len; ++i) {
            onSight[walls[i][0]][walls[i][1]] = -1;
        }
        for (int i = 0, len = guards.size(); i < len; ++i) {
            onSight[guards[i][0]][guards[i][1]] = -1;
        }
        for (int i = 0, len = guards.size(); i < len; ++i) {
            int r = guards[i][0];
            int c = guards[i][1];
            for (int j = c - 1; j >= 0; --j) {
                if (onSight[r][j] == -1) break;
                if (onSight[r][j] == 0) --guarded;
                ++onSight[r][j];
            }
            for (int j = c + 1; j < n; ++j) {
                if (onSight[r][j] == -1) break;
                if (onSight[r][j] == 0) --guarded;
                ++onSight[r][j];
            }
            for (int j = r - 1; j >= 0; --j) {
                if (onSight[j][c] == -1) break;
                if (onSight[j][c] == 0) --guarded;
                ++onSight[j][c];
            }
            for (int j = r + 1; j < m; ++j) {
                if (onSight[j][c] == -1) break;
                if (onSight[j][c] == 0) --guarded;
                ++onSight[j][c];
            }
        }
        return guarded;
    }
};