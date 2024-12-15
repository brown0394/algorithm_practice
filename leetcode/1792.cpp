class Solution {
    static bool compareD(vector<int>& one, vector<int>& two) {
        double oned = ((one[0] + 1) / (double)(one[1] + 1)) - (one[0] / (double)one[1]);
        double twod = ((two[0] + 1) / (double)(two[1] + 1)) - (two[0] / (double)two[1]);
        return oned < twod;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto comp = [](pair<double, double>& one, pair<double, double>& two) {
            double oned = ((one.first+1) / (one.second+1)) - (one.first / one.second);
            double twod = ((two.first+1) / (two.second+1)) - (two.first / two.second);
            return oned < twod;
        };
        priority_queue<pair<double, double>, vector<pair<double, double>>, decltype(comp)> pq(comp);
        int size = classes.size();
        for (int i = 0; i < size; ++i) {
            pq.push({classes[i][0], classes[i][1]});
        }
        for (int i = 0; i < extraStudents; ++i) {
            pair<double, double>p = pq.top();
            pq.pop();
            pq.push({p.first+1, p.second + 1});
        }
        double ans = 0;
        while (!pq.empty()) {
            const pair<double, double>& p = pq.top();
            ans += (p.first / p.second);
            pq.pop();
        }
        
        return ans / size;
    }
};