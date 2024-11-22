class Solution {
    struct node {
        vector<int> zeros;
        vector<int> ones;
    };
    bool compare(vector<int>& one, vector<int>& two) {
        int len = one.size();
        for (int i = 0; i < len; ++i) {
            if (one[i] != two[i]) return false;
        }
        return true;
    }

    bool compareEqLen(node& one, node& two) {
        if (one.ones[0] == two.ones[0]) {
            return compare(one.ones, two.ones);
        }
        if (one.ones[0] == two.zeros[0]) {
            return compare(one.ones, two.zeros);
        }
        return false;
    }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        if (col == 1) return row;
        list<node> rows;
        int equalCases = 0;
        for (int i = 0; i < row; ++i) {
            rows.emplace_back();
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j]) rows.back().ones.push_back(j);
                else rows.back().zeros.push_back(j);
            }
            if (rows.back().ones.empty() || rows.back().zeros.empty()) ++equalCases;
        }
        for (auto it = rows.begin(); it != rows.end(); ++it) {
            auto it2 = it;
            int count = 1;
            for (++it2; it2 != rows.end();) {
                bool equal = false;
                if (it->ones.size() == it->zeros.size()) {
                    if (it->ones.size() == it2->ones.size()) equal = compareEqLen(*it, *it2);
                }
                else if (it->ones.size() < it->zeros.size()) {
                    if (it->ones.size() == it2->ones.size()) equal = compare(it->ones, it2->ones);
                    else if (it->ones.size() == it2->zeros.size()) equal = compare(it->ones, it2->zeros);
                }
                else {
                    if (it->zeros.size() == it2->zeros.size()) equal = compare(it->zeros, it2->zeros);
                    else if (it->zeros.size() == it2->ones.size()) equal = compare(it->zeros, it2->ones);
                }
                if (equal) {
                    it2 = rows.erase(it2);
                    ++count;
                }
                else ++it2;
            }
            equalCases = max(equalCases, count);
        }
        return equalCases;
    }
};
