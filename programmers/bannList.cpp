#include <string>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct node {
    int depth;
    int visiting;
};

bool compare(string& one, string& two) {
    for (int i = 0; i < one.size(); ++i) {
        if (one[i] == '*') continue;
        if (one[i] != two[i]) return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<int>> possibleElems(banned_id.size());
    bitset<512> visit;
    visit.set();
    for (int i = 0; i < user_id.size(); ++i) {
        for (int j = 0; j < banned_id.size(); ++j) {
            if (user_id[i].size() == banned_id[j].size()
                && compare(banned_id[j], user_id[i])) {
                possibleElems[j].push_back(i);
            }
        }
    }
    int end = banned_id.size() - 1;
    if (!end) {
        return possibleElems[0].size();
    }
    queue<node> q;
    int depth, visiting, nextVisit;
    for (int i = 0; i < possibleElems[0].size(); ++i) {
        nextVisit = 1 << possibleElems[0][i];
        q.push(node{ 1, nextVisit });
        visit[nextVisit] = false;
    }
    while (!q.empty()) {
        depth = q.front().depth;
        visiting = q.front().visiting;
        q.pop();
        if (depth == end) {
            for (int i = 0; i < possibleElems[depth].size(); ++i) {
                nextVisit = visiting | (1 << possibleElems[depth][i]);
                if (visit[nextVisit]) {
                    visit[nextVisit] = false;
                    ++answer;
                }
            }
        }
        else {
            for (int i = 0; i < possibleElems[depth].size(); ++i) {
                nextVisit = visiting | (1 << possibleElems[depth][i]);
                if (visit[nextVisit]) {
                    visit[nextVisit] = false;
                    q.push(node{ depth + 1, nextVisit});
                }
            }
        }  
    }

    return answer;
}