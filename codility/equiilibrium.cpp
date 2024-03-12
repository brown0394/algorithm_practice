int solution(vector<int> &A) {
    int lower = A[0];
    int upper = 0;
    for (int i = 1; i < A.size(); ++i) upper += A[i];
    int minDiff = std::abs(lower - upper);
    for (int i = 2; i < A.size(); ++i) {
        lower += A[i-1];
        upper -= A[i-1];
        int diff = std::abs(lower - upper);
        if (diff < minDiff) minDiff = diff;
    }
    return minDiff;
}