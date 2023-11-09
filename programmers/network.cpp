#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int k;
    queue<int> q;
    bool first = true;
    for (int i = 0; i < computers.size(); ++i) {
        for (int j = 0; j < computers[i].size(); ++j) {
            if (computers[i][j]) {
                if (first) {
                    first = false;
                    ++answer;
                }
                if (i == j) continue;
                q.push(j);
                computers[i][j] = 0;
                computers[j][i] = 0;
            }
        }
        first = true;
        while (!q.empty()) {
            k = q.front();
            q.pop();
            for (int j = 0; j < computers[k].size(); ++j) {
                if (k == j) {
                    computers[k][j] = 0;
                }
                if (computers[k][j]) {
                    q.push(j);
                    computers[k][j] = 0;
                    computers[j][k] = 0;
                }
            }
        }
    }
    return answer;
}