#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int size = (minerals.size() / 5);
    if (minerals.size() % 5) ++size;
    vector<vector<int>> fiveMinerals(size, vector<int>(4));
    int count = 1;
    int idx = 0;
    for (string& str : minerals) {
        switch(str[0]) {
            case 'd' : {++fiveMinerals[idx][0]; break;}
            case 'i' : {++fiveMinerals[idx][1]; break;}
            case 's' : {++fiveMinerals[idx][2]; break;}
        }
        if (count == 5) {
            count = 0;
            fiveMinerals[idx][3] = idx;
            ++idx;
        }
        ++count;
    }
    if (count > 1) fiveMinerals[idx][3] = idx;
   sort(fiveMinerals.begin(), fiveMinerals.end(), [](vector<int>& one, vector<int>& two) {
        if (one[0] == two[0]) {
            if (one[1] == two[1]) return one[2] > two[2];
            return one[1] > two[1];
        }
        return one[0] > two[0];
    });
    idx = 0;
    int picksAmount = picks[0] + picks[1] + picks[2];
    while (idx < 3 && picks[idx] == 0) ++idx;

    for (int i = 0, len = fiveMinerals.size(); i < len && idx < 3; ++i) {
        if (fiveMinerals[i][3] >= picksAmount) continue;
        if (idx == 0) {
            answer += fiveMinerals[i][0] + fiveMinerals[i][1] + fiveMinerals[i][2];
        }
        else if (idx == 1) {
            answer += (fiveMinerals[i][0] * 5) + fiveMinerals[i][1] + fiveMinerals[i][2];
        }
        else {
            answer += (fiveMinerals[i][0] * 25) + (fiveMinerals[i][1] * 5) + fiveMinerals[i][2];
        }
        --picks[idx];
        if (0 == picks[idx]) {
            while (idx < 3 && picks[idx] == 0) ++idx;
        }
    }

    return answer;
}