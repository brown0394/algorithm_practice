#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int sDivN = s / n;
    printf("%d\n", sDivN);
    if (!sDivN) {
        answer.push_back(-1);
        return answer;
    }
    int mod = s % n;
    printf("mod : %d, n - mod : %d, n : %d\n", mod, n-mod, n);
    if (mod) {
        for (int i = 0; i < (n - mod); ++i) {
            answer.push_back(sDivN);
        }
        for (int i = (n - mod); i < n; ++i) {
            answer.push_back(sDivN + 1);
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            answer.push_back(sDivN);
        }
    }
    return answer;
}