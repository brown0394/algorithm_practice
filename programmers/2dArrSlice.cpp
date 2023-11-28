#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    int starti = left / n;
    int startj = left % n;
    int endi = right / n;
    int endj = right % n;
    int i = starti;
    for (; i < endi; ++i) {
        for (int j = startj; j < n; ++j) {
            if (j <= i)
                answer.push_back(i+1);
            else 
                answer.push_back(j+1);
        }
        startj = 0;
    }
    for (; i <= endi; ++i) {
        for (int j = startj; j <= endj; ++j) {
            if (j <= i)
                answer.push_back(i+1);
            else 
                answer.push_back(j+1);
        }
        startj = 0;
    }
    return answer;
}