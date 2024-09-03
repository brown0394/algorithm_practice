#include <iostream>
#include <vector>

int cities;
std::vector<std::vector<int>> path;
std::vector<std::vector<int>> pathCost;
const int INF = 1000000000;

void findPath(int cur, int bit) {
    for (int i = 1; i < cities; ++i) {
        if (!(bit & (1 << i)) && path[cur][i]) {
            int nextBit = bit | (1 << i);
            if (pathCost[i][nextBit] == 0) {
                findPath(i, nextBit);
                if (pathCost[i][nextBit] == 0) {
                    pathCost[i][nextBit] = INF;
                }
            }
            if (pathCost[i][nextBit] == INF) continue;
            if (pathCost[cur][bit] == 0) pathCost[cur][bit] = pathCost[i][nextBit] + path[cur][i];
            else if (pathCost[cur][bit] > pathCost[i][nextBit] + path[cur][i]) {
                pathCost[cur][bit] = pathCost[i][nextBit] + path[cur][i];
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> cities;
    path.resize(cities, std::vector<int>(cities));
    pathCost.resize(cities, std::vector<int>(1 << cities, 0));
    int bit = (1 << cities) - 1;
    for (int i = 0; i < cities; ++i) {
        std::cin >> path[i][0];
        if (path[i][0]) pathCost[i][bit] = path[i][0];
        for (int j = 1; j < cities; ++j) {
            std::cin >> path[i][j];
        }
    }
    findPath(0, 1);
    std::cout << pathCost[0][1] << '\n';
}