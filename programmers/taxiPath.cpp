#include <vector>
#include <map>


using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    map<int, int> checkList;
    vector<int> shouldVisit;
    vector<vector<int>> distanceTable(n, vector<int>(n, 0));
    for (auto it = fares.begin(); it != fares.end(); ++it) {
        distanceTable[(*it)[0]-1][(*it)[1]-1] = (*it)[2];
        distanceTable[(*it)[1]-1][(*it)[0]-1] = (*it)[2];
    }
    int idx;
    int curFare;
    for (int i = 0; i < n; ++i) {
        checkList.insert(make_pair(distanceTable[s-1][i], i));
    }
    while(!checkList.empty()) {
        auto it = checkList.begin();
        idx = it->second;
        curFare = it->first;
        checkList.erase(it);
        for (int j = 0; j < n; ++j) {
            if (s-1 == j) continue;
            int newFare = distanceTable[idx][j] + curFare;
            if (distanceTable[idx][j]) {
                if (distanceTable[s-1][j] == 0) {
                    distanceTable[s-1][j] = newFare;
                    distanceTable[j][s-1] = newFare;
                    checkList.insert(make_pair(distanceTable[s-1][j], j));
                    continue;
                }
                if (newFare < distanceTable[s-1][j]) {
                    distanceTable[s-1][j] = newFare;
                    distanceTable[j][s-1] = newFare;
                }
            }  
        }
    }
    for (int i = 0; i < n; ++i) {
        if (distanceTable[s-1][i]) {
            shouldVisit.push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i == s-1) continue;
        for (auto it = shouldVisit.begin(); it != shouldVisit.end(); ++it) {
            if (distanceTable[i][*it]) {
                checkList.insert(make_pair(distanceTable[i][*it], *it));
            }
        }
        while(!checkList.empty()) {
            auto it = checkList.begin();
            idx = it->second;
            curFare = it->first;
            checkList.erase(it);
            for (auto it = shouldVisit.begin(); it != shouldVisit.end(); ++it) {
                if (i == *it) continue;
                int newFare = distanceTable[idx][*it] + curFare;
                if (distanceTable[idx][*it]) {
                    if (distanceTable[i][*it] == 0) {
                        distanceTable[i][*it] = newFare;
                        distanceTable[*it][i] = newFare;
                        checkList.insert(make_pair(distanceTable[i][*it], *it));
                        continue;
                    }
                    if (newFare < distanceTable[i][*it]) {
                        distanceTable[i][*it] = newFare;
                        distanceTable[*it][i] = newFare;
                    }
                }  
            }
        }
    }

    
    answer = distanceTable[s-1][a-1] +
                distanceTable[s-1][b-1];
    for (auto it = shouldVisit.begin(); it != shouldVisit.end(); ++it) {
        if (distanceTable[s-1][*it]) {
            int comp = distanceTable[s-1][*it] + distanceTable[*it][a-1] +
                distanceTable[*it][b-1];
            if (comp && comp < answer) {
                answer = comp;
            }
        }
    }
    
    return answer;
}