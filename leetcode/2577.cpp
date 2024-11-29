class Solution {
    int row, col;
    vector<vector<int>> mark;
    bool checkValid(vector<vector<int>>& grid, int i, int j, int count) {
        if (i < 0 || i >=row || j < 0 || j >= col) return false;
        if (grid[i][j] <= count + 1) {
            if (mark[i][j] <= count + 1) return false;
            mark[i][j] = count+1;
        }
        else {
            if (count == 0) return false;
            if ((count % 2) + (grid[i][j] % 2) == 1) {
                if (mark[i][j] > grid[i][j]) {
                    mark[i][j] = grid[i][j];
                }
                else return false;
            }
            else {
                if (mark[i][j] > grid[i][j]+1) {
                    mark[i][j] = grid[i][j]+1;
                }
                else return false; 
            }
        }
        return true;
    }
public:
    int minimumTime(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        if (grid[0][0] > 0) return -1;
        mark.resize(row, vector<int>(col, numeric_limits<int>::max()));
        auto compare = [](vector<int>& one, vector<int>& two) {
            return one[2] > two[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            int i = pq.top()[0];
            int j = pq.top()[1];
            int count = pq.top()[2];
            pq.pop();
            if (i == row-1 && j == col-1) return count;
            if (checkValid(grid, i+1, j, count)) {
                pq.push({i+1, j, mark[i+1][j]});
            }
            if (checkValid(grid, i-1, j, count)) {
                pq.push({i-1, j, mark[i-1][j]});
            }
            if (checkValid(grid, i, j+1, count)) {
                pq.push({i, j+1, mark[i][j+1]});
            }
            if (checkValid(grid, i, j-1, count)) {
                pq.push({i, j-1, mark[i][j-1]});
            }
        }
        return -1;
    }
};