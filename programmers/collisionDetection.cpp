#include <string>
#include <vector>
#include <map>

using namespace std;

int checkOverlapp(vector<vector<map<int, bool>>>& road, int curR, int curJ, int curTime) {
    int collision = 0;
    auto found = road[curR][curJ].lower_bound(curTime);
    if (found != road[curR][curJ].end() && found->first == curTime) {
        if (!found->second) {
            ++collision;
        }
        found->second = true;
    }
    else {
        road[curR][curJ].emplace_hint(found, curTime, false);
    }
    return collision;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int row = 0, col = 0;
    for (int i = 0, len = points.size(); i < len; ++i) {
        if (row < points[i][0]) row = points[i][0];
        if (col < points[i][1]) col = points[i][1];
    }
    vector<vector<map<int, bool>>> road(row + 1, vector<map<int, bool>>(col + 1));
    int collisions = 0;
    for (int i = 0, lenI = routes.size(); i < lenI; ++i) {
        int curTime = 1;
        int curR = points[routes[i][0] - 1][0];
        int curJ = points[routes[i][0] - 1][1];
        collisions += checkOverlapp(road, curR, curJ, curTime++);
        for (int j = 1, lenJ = routes[i].size(); j < lenJ; ++j) {
            while (curR != points[routes[i][j] - 1][0]) {
                if (curR < points[routes[i][j] - 1][0]) ++curR;
                else --curR;
                collisions += checkOverlapp(road, curR, curJ, curTime++);
            }
            while (curJ != points[routes[i][j] - 1][1]) {
                if (curJ < points[routes[i][j] - 1][1]) ++curJ;
                else --curJ;
                collisions += checkOverlapp(road, curR, curJ, curTime++);
            }
        }
    }
    return collisions;
}