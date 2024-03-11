vector<int> solution(vector<int> &A, int K) {
    // Implement your solution here
    if (A.empty()) return A;
    int len = A.size();
    int shift = K % len;
    if (shift == 0) return A;
    std::vector<int> ans(len);
    int idx = 0;
    for (int i = shift; i < len; ++i) {
        ans[i] = A[idx++];
    }
    for (int i = 0; i < shift; ++i) {
        ans[i] = A[idx++];
    }
    return ans;
}