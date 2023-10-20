#include <string>
#include <vector>
#include <queue>

using namespace std;

struct moveData {
    int i;
    int j;
    int count;
};

int solution(vector<string> board) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<bool>> visit(row, vector<bool>(col, true));
    queue<moveData> q;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (board[i][j] == 'D') {
                visit[i][j] = false;
            }
            else if (board[i][j] == 'R') {
                q.push(moveData{ i, j, 0 });
                visit[i][j] = false;
            }
        }
    }
    int i, j, count;
    bool found = false;
    int steps;
    while (!q.empty()) {
        i = q.front().i;
        j = q.front().j;
        count = q.front().count + 1;
        steps = 1;
        q.pop();
        while (i + steps < row && board[i + steps][j] != 'D') ++steps;
        --steps;
        if (steps && visit[i + steps][j]) {
            if (board[i + steps][j] == 'G') {
                found = true;
                break;
            }
            visit[i + steps][j] = false;
            q.push(moveData{ i + steps, j, count });
        }
        steps = 1;
        while (i - steps >= 0 && board[i - steps][j] != 'D') ++steps;
        --steps;
        if (steps && visit[i - steps][j]) {
            if (board[i - steps][j] == 'G') {
                found = true;
                break;
            }
            visit[i - steps][j] = false;
            q.push(moveData{ i - steps, j, count });
        }
        steps = 1;
        while (j + steps < col && board[i][j + steps] != 'D') ++steps;
        --steps;
        if (steps && visit[i][j + steps]) {
            if (board[i][j + steps] == 'G') {
                found = true;
                break;
            }
            visit[i][j + steps] = false;
            q.push(moveData{ i, j + steps, count });
        }
        steps = 1;
        while (j - steps >= 0 && board[i][j - steps] != 'D') ++steps;
        --steps;
        if (steps && visit[i][j - steps]) {
            if (board[i][j - steps] == 'G') {
                found = true;
                break;
            }
            visit[i][j - steps] = false;
            q.push(moveData{ i, j - steps, count });
        }
    }

    int answer = -1;
    if (found) answer = count;
    return answer;
}

int main() {
    vector<string> board{"...D..R", ".D.G...", "....D.D", "D....D.", "..D...."};
    printf("%d\n", solution(board));
}