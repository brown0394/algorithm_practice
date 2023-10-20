#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int row = maps.size();
    int col = maps[0].size();
    vector<vector<bool>> visit(row, vector<bool>(col, true));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (maps[i][j] == 'X') {
                visit[i][j] = false;
            }
        }
    }
    queue<pair<int, int>> q;
    int sum;
    int k,l;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            sum = 0;
            if (visit[i][j]) {
                q.push(make_pair(i, j));
                sum += maps[i][j] - '0';
                visit[i][j] = false;
                while (!q.empty()) {
                    k = q.front().first;
                    l = q.front().second;
                    q.pop();
                    if (k + 1 < row && visit[k+1][l]) {
                        q.push(make_pair(k+1, l));
                        sum += maps[k+1][l] - '0';
                        visit[k+1][l] = false;
                    }
                    if (k - 1 >= 0 && visit[k-1][l]) {
                        q.push(make_pair(k-1, l));
                        sum += maps[k-1][l] - '0';
                        visit[k-1][l] = false;
                    }
                    if (l + 1 < col && visit[k][l+1]) {
                        q.push(make_pair(k, l+1));
                        sum += maps[k][l+1] - '0';
                        visit[k][l+1] = false;
                    }
                    if (l - 1 >= 0 && visit[k][l-1]) {
                        q.push(make_pair(k, l-1));
                        sum += maps[k][l-1] - '0';
                        visit[k][l-1] = false;
                    }
                }
                if (sum) {
                    answer.push_back(sum);
                }
            }
        }
    }
    if (answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;
}