int solution(int X, vector<int> &A) {
    if (A.empty()) return -1;
    std::set<int> leaves;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] <= X) leaves.insert(A[i]);
        if (leaves.size() == X) return i;
    }
    return 0;
}
