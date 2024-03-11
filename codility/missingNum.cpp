int solution(vector<int> &A) {
    // Implement your solution here
    if (A.empty()) return 1;
    if (A.size() == 1) {
        if (A[0] == 1) return 2;
        else return 1;
    }
    std::sort(A.begin(), A.end());
    if (A[0] != 1) return 1;
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] - A[i - 1] > 1) return A[i] - 1;
    }
    return A.back() + 1;
}