#include string
#include vector
#include algorithm

using namespace std;

struct VisitRecord {
  bool visited;
  int lastIdx;
};

bool sortStd(char one, char two) {
    return one  two;
}

string solution(string X, string Y) {
    string answer = ;
    int visited[10]{0};
    for (int i = 0; i  X.size(); ++i) {
        for (int j = visited[X[i] - '0']; j  Y.size(); ++j) {
            if (X[i] == Y[j]) {
                answer.push_back(X[i]);
                visited[X[i] - '0'] = j + 1;
                break;
            }
        }
    }
    if (answer.size() == 0) {
        answer = -1;
    }
    else {
        sort(answer.begin(), answer.end(), sortStd);
        if (answer[0] == '0') answer = 0;
    }
    return answer;
}