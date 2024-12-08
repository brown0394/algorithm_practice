class Solution {
    struct info {
        int time;
        int val;
        bool isStart;

        bool operator <(const info& other) {
            if (time == other.time) {
                if (isStart && !other.isStart) return true;
                return false;
            }
            return time < other.time;
        }
    };
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int size = events.size();
        vector<info> infos(size * 2);
        for (int i = 0, cur = 0; i < size; ++i) {
            infos[cur].time = events[i][0];
            infos[cur].val = events[i][2];
            infos[cur++].isStart = true;
            infos[cur].val = events[i][2];
            infos[cur].time = events[i][1];
            infos[cur++].isStart = false;
        }
        sort(infos.begin(), infos.end());
        int maxV = 0;
        int tilMax = 0;
        size <<= 1;
        for (int i = 0; i < size; ++i) {
            if (infos[i].isStart) {
                maxV = max(maxV, infos[i].val + tilMax);
            }
            else {
                tilMax = max(tilMax, infos[i].val);
            }
        }
        return maxV;
    }
};