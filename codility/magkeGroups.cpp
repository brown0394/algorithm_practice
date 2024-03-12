bool check(vector<int> &A, int val, int k) {
    int groups = 1;
    int sum = 0;
    for (auto it = A.begin(); it != A.end(); ++it) {
        if (sum + *it <= val) sum += *it;
        else {
            if (groups == k) return false;
            if (*it > val) return false;
            ++groups;
            sum = *it;
        }
    }
    return true;
}

int solution(int K, int M, vector<int> &A) {
    int low = 0;
    int high = M * A.size() + 1;
    int mid = (low + high) >> 1;
    while (low < high) {
        if (check(A, mid, K)) {
            high = mid;
        }
        else low = mid + 1;
        mid = (low + high) >> 1;
    }
    return low;
}