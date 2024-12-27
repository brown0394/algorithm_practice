class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int last = values.size()-1;
        int maxV = values[last] + values[last-1] - 1;
        for (int i = last-2; i >= 0; --i) {
            int calc = values[i] + values[i+1] - 1;
            int lastC = values[i] + values[last] + i - last;
            if (calc >= lastC) {
                maxV = max(maxV, calc);
                last = i+1;
            }
            else maxV = max(maxV, lastC);
        }
        return maxV;
    }
};