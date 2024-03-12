int solution(vector<int> &A) {
    if (A.empty()) return 0;
    std::set<int> check;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] > 0) check.insert(A[i]);
    }
    if (check.empty()) return 1;
    auto it = check.begin();
    if (*it > 1) return 1;
    int last = *it;
    for (++it; it != check.end(); ++it) {
        if (*it - last > 1) return last + 1;
        last = *it;
    }
    return *(--it) + 1;
}