#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> paths(n+1, vector<int>(n+1, 0));
    vector<bool> visit(n+1, true);
    for (int i = 0; i < edge.size(); ++i) {
        paths[edge[i][0]][edge[i][1]] = 1;
        paths[edge[i][1]][edge[i][0]] = 1;
    }
    visit[1] = false;
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    int to, dist;
    while (!q.empty()) {
        to = q.front().first;
        dist = q.front().second;
        q.pop();
        for (int i = 2; i <= n; ++i) {
            if (paths[to][i] && visit[i]) {
                q.push(make_pair(i, dist+1));
                paths[1][i] = dist+1;
                visit[i] = false;
            }
        }
    }
    answer = 1;
    if (n > 2) {
        sort(paths[1].begin(), paths[1].end(), greater<int>());
        int last = paths[1][0];
        for (int i = 1; i <= n; ++i) {
            if (paths[1][i] != last) break;
            ++answer;
        }
    }

    return answer;
}