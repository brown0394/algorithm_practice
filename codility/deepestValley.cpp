 #include <vector>
using namespace std;

void checkSubHeight(vector<int>& A, int& i, int& maxDepth, int& minHeight) {
    int cur = A[i];
    minHeight = A[i];
    maxDepth = 0;
    int len = A.size();
    bool up = false;
    for (++i; i < len; ++i) {
        if (A[i] >= cur) {
            if (maxDepth < cur - minHeight) maxDepth = cur - minHeight;
            return;
        }
        else if (A[i] > A[i - 1]) up = true;
        else if (A[i] < A[i-1]) {
            if (up) {
                --i;
                if (A[i] - minHeight > maxDepth) maxDepth = A[i] - minHeight;
                int subMaxD, subMinHeight;
                checkSubHeight(A, i, subMaxD, subMinHeight);
                if (subMaxD > maxDepth) maxDepth = subMaxD;
                if (subMinHeight < minHeight) minHeight = subMinHeight;
                if (i >= len) break;
                --i;
            }
            else if (minHeight > A[i]) minHeight = A[i];
            up = false;
        }
    }
    if (up && maxDepth < A[len - 1] - minHeight) maxDepth = A[len - 1] - minHeight;
}

int solution(vector<int>& A) {
    // Implement your solution here
    int cur = A[0];
    int minHeight = A[0];
    int maxDepth = 0;
    int len = A.size();
    int i = 1;
    bool up = false;
    for (; i < len; ++i) {
        if (cur > A[i]) break;
        cur = A[i];
        minHeight = A[i];
    }
    for (; i < len; ++i) {
        if (A[i] >= cur) {
            if (cur - minHeight > maxDepth) maxDepth = cur - minHeight;
            minHeight = A[i];
            minHeight = A[i];
            cur = A[i];
            up = false;
        }
        else if (A[i] > A[i - 1]) up = true;
        else if (A[i] < A[i-1]) {
            if (up) {
                --i;
                if (A[i] - minHeight > maxDepth) maxDepth = A[i] - minHeight;
                int subMaxD, subMinHeight;
                checkSubHeight(A, i, subMaxD, subMinHeight);
                if (subMaxD > maxDepth) maxDepth = subMaxD;
                if (subMinHeight < minHeight) minHeight = subMinHeight;
                --i;
            }
            else if (minHeight > A[i]) minHeight = A[i];
            up = false;
        }
    }
    if (up && maxDepth < A[len - 1] - minHeight) maxDepth = A[len - 1] - minHeight;
    return maxDepth;
}

int main() {
    vector<int> A{ 20, 4, 10, 1, 10, 1, 30 };
    solution(A);
}