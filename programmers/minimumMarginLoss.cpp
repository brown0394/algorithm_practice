#include <string>
#include <vector>
#include <stack>

using namespace std;

struct node {
    int cur;
    int num;
};

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    vector<vector<int>> tree(sales.size());
    vector<vector<int>> members(sales.size(), vector<int>(2, 0));
    for (int i = 0; i < links.size(); ++i) {
        tree[links[i][0] - 1].push_back(links[i][1] - 1);//push child
    }
    stack<node> stk;
    stk.push(node{ 0, 0 });
    int cur, num;
    while (!stk.empty()) {
        cur = stk.top().cur;
        num = stk.top().num;
        if (tree[num].empty()) {
            stk.pop();
            members[num][0] = sales[num];
            members[num][1] = 0;
        }
        else {
            if (tree[num].size() == cur) {
                members[num][0] = sales[num];
                int min = sales[num];
                int member, val;
                int secondNum = tree[num][0];
                int secondMin = members[secondNum][0] - members[secondNum][1];
                int minNum = num;
                int i = 0;
                bool minus = false;
                for (; i < tree[num].size(); ++i) {
                    member = tree[num][i];
                    val = members[member][0] - members[member][1];
                    if (val < 0) {
                        answer += val;
                        minus = true;
                        ++i;
                        break;
                    }
                    if (val < min) {
                        secondNum = minNum;
                        secondMin = min;
                        min = val;
                        minNum = member;
                    }
                    else if (val < secondMin) {
                        secondNum = member;
                        secondMin = val;
                    }
                }
                for (; i < tree[num].size(); ++i) {
                    member = tree[num][i];
                    val = members[member][0] - members[member][1];
                    if (val < 0) {
                        answer += val;
                    }
                }
                stk.pop();
                if (minus) {
                    members[num][1] = 0;
                }
                else {
                    if (num == minNum) {
                        if (stk.empty()) {
                            val = members[minNum][0] - members[minNum][1];
                        }
                        else {
                            val = members[secondNum][0] - members[secondNum][1];
                        }
                    }
                    else {
                        val = members[minNum][0] - members[minNum][1];
                    }
                    answer += val;
                    members[num][1] = val;
                }
            }
            else {
                stk.push(node{ 0, tree[num][stk.top().cur++] });
            }
        }
    }
    return answer;
}