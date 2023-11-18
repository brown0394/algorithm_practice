#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int open;
    int close;
};

int solution(int n) {
    int answer = 0;
    queue<node> q;
    q.push(node{ n - 1, n});
    int open, close;
    while (!q.empty()) {
        open = q.front().open;
        close = q.front().close;
        if (!open) {
            ++answer;
        }
        else {
            q.push(node{ open - 1, close });
            if (close - 1 >= open) {
                q.push(node{ open, close - 1 });
            }
        }
        q.pop();
    }
    return answer;
}