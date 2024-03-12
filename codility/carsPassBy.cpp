int solution(vector<int> &A) {
    if (A.empty()) return 0;
    std::vector<int> east;
    std::vector<int> west;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i]) west.push_back(i);
        else east.push_back(i);
    }
    if (west.empty() || east.empty()) return 0;
    int westIdx = 0, westLen = west.size();
    int passingCars = 0;
    for (int i = 0; i < east.size(); ++i) {
        for (; westIdx < westLen; ++westIdx) {
            if (west[westIdx] > east[i]) break;
        }
        passingCars += westLen - westIdx;
        if (passingCars > 1'000'000'000) return -1;
    }
    return passingCars;
}