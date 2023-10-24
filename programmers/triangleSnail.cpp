#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail(n);
    for (int i = 1; i <= n; ++i) {
        snail[i - 1].reserve(i);
        for (int j = 0; j < i; ++j) {
            snail[i - 1].push_back(0);
        }
    }
    int num = (n * (n + 1)) >> 1;
    int left = 0;
    int step = 0;
    int circle = 0;
    int lim = n-1;
    int base = 0;
    int leftCount = 0;
    int stepCount = 0;
    for (int i = 1; i <= num; ++i) {
        if (circle == 0) {
            if (stepCount == lim - 1) {
                ++circle;
                stepCount = -1;
            }
            snail[step++][left] = i;
            ++stepCount;
        }
        else if (circle == 1) {
            if (leftCount == lim - 1) {
                ++circle;
                leftCount = -1;
            }
            snail[step][left++] = i;
            ++leftCount;
        }
        else if (circle == 2) {
            if (step == base + 1) {
                circle = 0;
                lim -= 3;
                base += 2;
                snail[step++][left] = i;
            }
            else {
                snail[step--][left--] = i;
            }
        }
    }
    answer.reserve(num + 1);
    for (auto it1 = snail.begin(); it1 != snail.end(); ++it1) {
        for (auto it2 = it1->begin(); it2 != it1->end(); ++it2) {
            answer.push_back(*it2);
        }
    }
    return answer;
}

int main() {
    vector<int> answer = solution(7);
    int a = 0;
}