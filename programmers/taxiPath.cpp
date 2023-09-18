#include <vector>

#define INF 1000000000
using namespace std;
void print(vector<vector<int>>& table) {
    for (auto it = table.begin(); it != table.end(); ++it) {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
            printf("%d ", *it2);
        }
        printf("\n");
    }
    printf("\n\n");
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    vector<vector<int>> distanceTable(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        distanceTable[i][i] = 0;
    }
    for (auto it = fares.begin(); it != fares.end(); ++it) {
        distanceTable[(*it)[0] - 1][(*it)[1] - 1] = (*it)[2];
        distanceTable[(*it)[1] - 1][(*it)[0] - 1] = (*it)[2];
    }
    print(distanceTable);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                for (int k = 0; k < distanceTable[j].size(); ++k) {
                    if (k != j) {
                        if (distanceTable[j][k] > distanceTable[j][i] + distanceTable[i][k]) {
                            distanceTable[j][k] = distanceTable[j][i] + distanceTable[i][k];
                        }
                    }
                }
            }
        }
    }
    print(distanceTable);
    answer = distanceTable[s - 1][a - 1] +
        distanceTable[s - 1][b - 1];
    for (int i = 0; i < n; ++i) {
        if (distanceTable[s - 1][i] < INF) {
            int comp = distanceTable[s - 1][i] + distanceTable[i][a - 1] +
                distanceTable[i][b - 1];
            if (comp < answer) {
                answer = comp;
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> fares{{2, 6, 6}, { 6, 3, 7 }, { 4, 6, 7 }, { 6, 5, 11 }, { 2, 5, 12 }, { 5, 3, 20 }, { 2, 4, 8 }, {4, 3, 9}};
    printf("%d\n", solution(6, 4, 5, 6, fares));
}