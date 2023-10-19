#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <algorithm>

using namespace std;
struct node {
    int idx;
    int child;
};

bool dfs(vector<int>& num, vector<vector<int>>& tree, int k, int root, int div) {
    vector<int>tempNum(num);
    stack<node> stk;
    stk.push(node{ root, 0 });
    int divideCount = 0;
    int idx;
    while (!stk.empty()) {
        idx = stk.top().idx;
        if (stk.top().child < tree[idx].size()) {
            stk.push(node{ tree[idx][stk.top().child++], 0 });
        }
        else {
            if (tree[idx].size() == 1) {
                if (tempNum[tree[idx][0]] + tempNum[idx] <= div) {
                    tempNum[idx] += tempNum[tree[idx][0]];
                }
                else {
                    ++divideCount;
                }
            }
            else if (tree[idx].size() > 1) {
                if (tempNum[tree[idx][0]] + tempNum[idx] + tempNum[tree[idx][1]] <= div) {
                    tempNum[idx] += tempNum[tree[idx][0]] + tempNum[tree[idx][1]];
                }
                else if (tempNum[tree[idx][0]] + tempNum[idx] <= div && tempNum[tree[idx][0]] <= tempNum[tree[idx][1]]) {
                    tempNum[idx] += tempNum[tree[idx][0]];
                    ++divideCount;
                }
                else if (tempNum[tree[idx][1]] + tempNum[idx] <= div && tempNum[tree[idx][0]] >= tempNum[tree[idx][1]]) {
                    tempNum[idx] += tempNum[tree[idx][1]];
                    ++divideCount;
                }
                else {
                    divideCount += 2;
                }
            }
            if (divideCount > k) return false;
            stk.pop();
        }
    }
    return true;
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int l = *max_element(num.begin(), num.end());
    if (k == num.size()) return l;
    vector<vector<int>> tree(num.size());
    int idx = num.size() - 1;
    int root = (idx * (idx + 1)) >> 1;
    for (int i = 0; i < links.size(); ++i) {
        if (links[i][0] >= 0) {
            tree[i].push_back(links[i][0]);
            root -= links[i][0];
        }
        if (links[i][1] >= 0) {
            tree[i].push_back(links[i][1]);
            root -= links[i][1];
        }
    }
    int sum = accumulate(num.begin(), num.end(), 0);



    int answer = (sum / k) << 1;
    int half = l + ((answer - l) >> 1);
    --k;
    while (l < answer) {
        if (dfs(num, tree, k, root, half)) {
            answer = half - 1;
        }
        else {
            l = half + 1;
        }
        half = l + ((answer - l) >> 1);
    }
    if (!dfs(num, tree, k, root, half)) {
        ++answer;
    }
    if (answer < l) answer = l;
    return answer;
}

int main() {
    vector<int> num {6}//, 9, 7, 5};//{12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1};
    vector<vector<int>> links{ {-1, -1} , { -1, -1 }, { -1, 0 }, { 2, 1 }}; //{ { -1, -1}, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 8, 5 }, { 2, 10 }, { 3, 0 }, { 6, 1 }, { 11, -1 }, { 4, 7 }, { -1, -1 }, { -1, -1 }};
    printf("%d\n", solution(4, num, links));
}