#include <string>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct node {
    int cur;
    list<int> leaves;
    int sheep;
    int wolves;
};

void makeTree(vector <vector<int>>& tree, vector<vector<int>>& edges) {
    for (int i = 0; i < edges.size(); ++i) {
        if (tree[edges[i][1]].empty()) {
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        else {
            int num = tree[edges[i][1]][0];
            tree[edges[i][1]][0] = edges[i][0];
            tree[edges[i][1]].push_back(num);
        }
        tree[edges[i][0]].push_back(edges[i][1]);
    }
    if (tree[0].size() > 1) {
        tree[0].push_back(tree[0][1]);
        tree[0][1] = tree[0][0];
    }
    else {
        tree[0].push_back(tree[0][0]);
    }
    tree[0][0] = 0;
}

void pruneTree(vector <vector<int>>& tree, vector<int>& info) {
    for (int i = 0; i < info.size(); ++i) {
        if (tree[i].size() == 1 && info[i]) {
            vector<int>* cur = &tree[i];
            int curNum = i;
            int parent = (*cur)[0];
            while (true) {
                if (tree[parent].size() > 2) {
                    if (tree[parent][1] == curNum) {
                        tree[parent][1] = tree[parent][2];
                    }
                    tree[parent].pop_back();
                    break;
                }
                else {
                    tree[parent].pop_back();
                    if (!info[parent]) {
                        break;
                    }
                    curNum = parent;
                    cur = &tree[curNum];
                    parent = (*cur)[0];
                }
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 1;
    vector <vector<int>> tree(info.size());
    makeTree(tree, edges);
    pruneTree(tree, info);
    vector<bool> visit(1 << static_cast<int>(info.size()), true);
    queue<node> q;
    list<int>* leaves;
    if (tree[0].size() > 1) {
        q.push(node{ 1, list<int>{tree[0][1], tree[0][2]}, 1, 0 });
    }
    else {
        q.push(node{ 1, list<int>{tree[0][1]}, 1, 0 });
    }
    list<int> test;
    test.remove(5);
    visit[1] = false;
    int cur, nxt, sheep, wolves, nextS, nextW;
    while (!q.empty()) {
        leaves = &q.front().leaves;
        cur = q.front().cur;
        sheep = q.front().sheep;
        wolves = q.front().wolves;
        for (auto it = leaves->begin(); it != leaves->end(); ++it) {
            int nextNode = *it;
            nxt = cur | (1 << (nextNode));
            nextS = sheep;
            nextW = wolves;
            if (info[nextNode]) ++nextW;
            else ++nextS;
            if (visit[nxt] && (nextS - nextW)) {
                visit[nxt] = false;
                q.push(node{ nxt, *leaves, nextS, nextW });
                q.back().leaves.remove(nextNode);
                if (tree[nextNode].size() > 1) {
                    q.back().leaves.push_back(tree[nextNode][1]);
                }
                if (tree[nextNode].size() > 2) {
                    q.back().leaves.push_back(tree[nextNode][2]);
                }
                if (nextS > answer) {
                    answer = nextS;
                }
            }
        }
        q.pop();
    }

    return answer;
}