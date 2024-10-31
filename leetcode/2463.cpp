class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        vector<int> factoryLocs;
        for (int i = 0, len = factory.size(); i < len; ++i) {
            for (int j = 0; j < factory[i][1]; ++j) factoryLocs.push_back(factory[i][0]);
        }
        sort(factoryLocs.begin(), factoryLocs.end());
        int factories = factoryLocs.size(), robots = robot.size();
        vector<vector<long long>> dists(2, vector<long long>(factories + 1));
        int cur = 0, last = 1;
        for (int i = robots - 1; i >= 0; --i) {
            if (i < robots - 1) dists[last][factories] = INT_MAX;
            dists[cur][factories] = INT_MAX;
            for (int j = factories - 1; j >= 0; --j) {
                long long whenRepair = abs(robot[i] - factoryLocs[j]) + dists[last][j + 1];
                long long whenSkipping = dists[cur][j + 1];
                dists[cur][j] = min(whenRepair, whenSkipping);
            }
            swap(cur, last);
        }
        return dists[last][0];
    }
};