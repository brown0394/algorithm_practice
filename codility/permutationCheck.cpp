int solution(vector<int> &A) {
    if (A.empty()) return 0;
    std::set<int> check;
    int len = A.size();
    for (int i = 0; i < len; ++i) {
        if (A[i] <= len) check.insert(A[i]);
        if (check.size() == len) return 1;
    }
    return 0;
}