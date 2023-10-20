#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int getDifferences(string& one, string& two) {
    int count = 0;
    for (int i = 0; i < one.size(); ++i) {
        if (one[i] != two[i]) ++count;
    }
    return count;
}

int solution(string begin, string target, vector<string> words) {
    int curDiff = getDifferences(begin, target);
    printf("%d\n", curDiff);
    bool found = false;
    int goalIdx;
    vector<int> diffs(words.size());
    vector<bool> visit(words.size(), true);
    for (int i = 0; i < words.size(); ++i) {
        diffs[i] = getDifferences(words[i], target);
        if (diffs[i] == 0) {
            found = true;
            goalIdx = i;
        }
    }
    if (!found) return 0;
    int count = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < diffs.size(); ++i) {
        if (visit[i] && diffs[i] <= curDiff &&
            getDifferences(words[i], begin) == 1) {
            if (i == goalIdx) return count + 1;
            q.push(make_pair(i, count+1));
            visit[i] = false;
        }
    }
    int curIdx = 0;
    while (!q.empty()) {
        curIdx = q.front().first;
        count = q.front().second;
        q.pop();
        for (int i = 0; i < diffs.size(); ++i) {
            if (visit[i] && diffs[i] <= diffs[curIdx] &&
                getDifferences(words[i], words[curIdx]) == 1) {
                q.push(make_pair(i, count + 1));
                if (i == goalIdx) return count + 1;
            }
        }
    }

    int answer = count;
    return answer;
}