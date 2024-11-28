class Solution {
    struct wallCounts{
        int i, j, count;
    };
    vector<vector<int>> mark;
    int row, col;
    deque<wallCounts> dq;
    void checkAndPush(deque<wallCounts>& dq, vector<vector<int>>& grid, int i, int j, int count) {
        if (i < 0 || j < 0 || i >= row || j >= col) return;
        count += grid[i][j];
        if (mark[i][j] <= count) return;
        mark[i][j] = count;
        if (grid[i][j]) dq.push_back({i, j, count});
        else dq.push_front({i, j, count});
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        mark.resize(row, vector<int>(col, row*col));
        dq.push_back({0, 0, grid[0][0]});
        while (!dq.empty()) {
            wallCounts wc = dq.front();
            dq.pop_front();
            checkAndPush(dq, grid, wc.i-1, wc.j, wc.count);
            checkAndPush(dq, grid, wc.i+1, wc.j, wc.count);
            checkAndPush(dq, grid, wc.i, wc.j-1, wc.count);
            checkAndPush(dq, grid, wc.i, wc.j+1, wc.count);
        }
        return mark[row-1][col-1];
    }
};