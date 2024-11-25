class Solution {
    string target;
    unordered_set<string> visit;
    bool tryPossibility(queue<pair<string, int>>& q, int offset) {
        string& str = q.front().first;
        int zero = q.front().second;
        swap(str[zero], str[zero + offset]);
        auto found = visit.find(str);
        if (found == visit.end()) {
            if (str == target) return true;
            visit.insert(str);
            q.push({str, zero + offset});
        }
        swap(str[zero], str[zero + offset]);
        return false;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string cur;
        target = "123450";
        int bidx = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                cur.push_back(board[i][j] + '0');
                if (board[i][j] == 0) bidx = cur.size()-1;
            }
        }
        if (cur == target) return 0;
        
        visit.insert(cur);
        queue<pair<string, int>> q;
        q.push({cur, bidx});
        int count = 1;
        while (!q.empty()) {
            int til = q.size();
            for (int i = 0; i < til; ++i) {
                string& str = q.front().first;
                int zero = q.front().second;
                if (zero != 0 && zero != 3) {
                    if (tryPossibility(q, -1)) return count;
                }
                if (zero != 2 && zero != 5) {
                    if (tryPossibility(q, 1)) return count;
                }
                if (zero >= 3) {
                    if (tryPossibility(q, -3)) return count;
                }
                if (zero < 3) {
                    if (tryPossibility(q, +3)) return count;
                }
                q.pop();
            }
            ++count;
        }
        return -1;
    }
};