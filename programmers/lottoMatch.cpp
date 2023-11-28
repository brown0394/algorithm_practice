#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    int zeros = 0;
    int match = 0;
    int idx = 0;
    int len = lottos.size();
    while (!lottos[idx] && idx < len) {
        ++zeros;
        ++idx;
    }
    for (int i = 0; i < win_nums.size(); ++i) {
        while (idx < len && lottos[idx] <= win_nums[i]) {
            if (lottos[idx] == win_nums[i]) ++match;
            ++idx;
        }
    }
    answer.push_back(7 - (zeros + match));
    answer.push_back(7 - match);
    if (answer[0] > 6) answer[0] = 6;
    if (answer[1] > 6) answer[1] = 6;
    return answer;
}