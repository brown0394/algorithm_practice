#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sortStandard(vector<int>& one, vector<int>& two) {
    return one[1] > two[1];
}

bool sortByRequestTime(vector<int>& one, vector<int>& two) {
    if (one[0] == two[0]) {
        return one[1] < two[1];
    }
    return one[0] < two[0];
}

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), sortByRequestTime);
    int answer = 0;
    int time = 0;
    int curIdx = 1;
    if (jobs.size() == 1) {
        return jobs[0][1];
    }
    time = (jobs[0][0] + jobs[0][1]);
    answer += jobs[0][1];
    vector<vector<int>> jobsHeap;
    while (curIdx < jobs.size()) {
        if (jobs[curIdx][0] > time && jobsHeap.empty()) {
            time = (jobs[curIdx][0] + jobs[curIdx][1]);
            answer += jobs[curIdx][1];
            ++curIdx;
        }
        else {
            int lastIdx = curIdx;
            while (curIdx < jobs.size() && jobs[curIdx][0] <= time) {
                jobsHeap.push_back(jobs[curIdx]);
                ++curIdx;
            }
            if (lastIdx < curIdx) {
                make_heap(jobsHeap.begin(), jobsHeap.end(), sortStandard);
            }
            pop_heap(jobsHeap.begin(), jobsHeap.end(), sortStandard);
            answer += ((time - jobsHeap.back()[0]) + jobsHeap.back()[1]);
            time += jobsHeap.back()[1];
            jobsHeap.pop_back();
        }
    }

    while (!jobsHeap.empty()) {
        pop_heap(jobsHeap.begin(), jobsHeap.end(), sortStandard);
        answer += ((time - jobsHeap.back()[0]) + jobsHeap.back()[1]);
        time += jobsHeap.back()[1];
        jobsHeap.pop_back();
    }
    answer = (float)answer / jobs.size();
    return answer;
}

int main() {
    vector<vector<int>> jobs {{0, 6}, { 2, 8 }, { 3, 7 }, { 7, 1 }, { 11, 11 }, { 19, 25 }, { 30, 15 }, { 32, 6 }, { 40, 3 }};
    printf("%d\n", solution(jobs));
}