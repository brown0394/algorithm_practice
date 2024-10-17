#include <string>
#include <vector>

using namespace std;

bool checkSolvablility(vector<int>& diffs, vector<int>& times, long long limit, int level) {
    long long last = 0;
    long long curTime = 0;
    for (int i = 0, len = times.size(); i < len; ++i) {
        curTime += times[i];
        if (diffs[i] > level) {
            curTime += (last + times[i]) * (diffs[i] - level);
        }
        if (curTime > limit) return false;
        last = times[i];
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    int high = 0;
    for (int i = 0, len = times.size(); i < len; ++i) {
        if (high < diffs[i]) high = diffs[i];
    }
    int low = 1;
    while (low <= high) {
        int mid = (high + low) >> 1;
        if (checkSolvablility(diffs, times, limit, mid)) {
            high = mid - 1;
            answer = mid;
        }
        else low = mid + 1;
    }
    return answer;
}