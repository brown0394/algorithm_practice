vector<int> solution(int N, vector<int> &A) {
    if (A.empty()) return A;
    std::vector<int> counters(N);
    int max = 0, maxCount = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] > N) maxCount = max;
        else {
            if (counters[A[i]-1] < maxCount) counters[A[i]-1] = maxCount;
            ++counters[A[i]-1];
            if (counters[A[i]-1] > max) max = counters[A[i]-1];
        }
    }
    for (int i = 0; i < N; ++i) {
        if (counters[i] < maxCount) counters[i] = maxCount;
    }
    return counters;
}