#include <vector>
using namespace std;


bool check(vector<int>& A, vector<int>& B, vector<int>& C, int len) {
    vector<int> range((C.size() << 1) + 1, 0);
    for (int i = 0; i < len; ++i) {
        ++range[C[i]];
    }
    for (int i = 1, size = range.size(); i < size; ++i) {
        range[i] += range[i-1];
    }
    for (int i = 0, size = A.size(); i < size; ++i) {
        if (range[B[i]] == range[A[i] - 1]) return false;
    }
    return true;
}

int solution(vector<int>& A, vector<int>& B, vector<int>& C) {
    int high = C.size();
    int low = 1;
    int mid = 0;

    int min = -1;
    while (low <= high) {
        mid = (high + low) >> 1;
        if (check(A, B, C, mid)) {
            high = mid - 1;
            min = mid;
        }
        else low = mid + 1;
    }
    return min;
}

int main() {
    vector<int> A{1};
    vector<int> B{2};
    vector<int> C{2};
    solution(A, B, C);
}