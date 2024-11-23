class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size()-1;
        int col = box[0].size()-1;
        vector<vector<char>> rotatedBox(col+1, vector<char>(row+1));

        for (int i = row; i >= 0; --i) {
            int j = col;
            int f = 0;
            while (j >= 0 && box[i][j] != '.') {
                rotatedBox[j][row-i] = box[i][j];
                --j;
            }
            f = j--;
            while (j >= 0) {
                if (box[i][j] == '#') {
                    rotatedBox[f][row-i] = '#';
                    --f;
                }
                else if (box[i][j] == '*') {
                    while (f > j) {
                        rotatedBox[f][row-i] = '.';
                        --f;
                    }
                    rotatedBox[f][row-i] = '*';
                    --f;
                }
                --j;
            }
            while (f >= 0) {
                rotatedBox[f][row-i] = '.';
                --f;
            }
        }
        return rotatedBox;
    }
};