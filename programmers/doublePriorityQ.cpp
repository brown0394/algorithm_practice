#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int compMax(int one, int two) {
    return one < two;
}
int compMin(int one, int two) {
    return one > two;
}

void popQ(vector<int>& q1, vector<int>& q2, int (*compFunc1)(int, int),
    int (*compFunc2)(int, int)) {
    pop_heap(q1.begin(), q1.end(), compFunc1);
    int num = q1.back();
    q1.pop_back();
    for (int i = q2.size() - 1; i >= 0; --i) {
        if (q2[i] == num) {
            q2.erase(q2.begin() + i);
            break;
        }
    }
    make_heap(q2.begin(), q2.end(), compFunc2);
}

void popMinMax(vector<int>& maxQ, vector<int>& minQ, char op) {
    if (maxQ.empty()) return;
    if (op == '-') {
        popQ(minQ, maxQ, compMin, compMax);
        return;
    }
    popQ(maxQ, minQ, compMax, compMin);
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> maxQ;
    vector<int> minQ;
    int num;
    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i][0] == 'I') {
            num = atoi(&operations[i][2]);
            maxQ.push_back(num);
            minQ.push_back(num);
            push_heap(maxQ.begin(), maxQ.end(), compMax);
            push_heap(minQ.begin(), minQ.end(), compMin);
        }
        else {
            popMinMax(maxQ, minQ, operations[i][2]);
        }
    }
    if (maxQ.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(maxQ[0]);
        answer.push_back(minQ[0]);
    }
    return answer;
}