class Solution {
    struct inRange {
        int rangeN;
        int val;
        inRange(int r, int v) : rangeN(r), val(v) {}
        bool operator < (const inRange& other) const {
            if (val == other.val) return rangeN < other.rangeN;
            return val < other.val;
        }
    };
    int INVALID = 1000000;
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<inRange> pq;
        for (int i = 0, size1 = nums.size(); i < size1; ++i) {
            for (int j = 0, jsize = nums[i].size(); j < jsize; ++j) {
                pq.emplace(i, nums[i][j]);
            }
        }
        int groupsCount = 0;
        int groups = nums.size();
        vector<int> members(groups, INVALID);
        map<int, int> memberMap;
        while (groupsCount < groups) {
            const inRange& element = pq.top(); 
            if (members[element.rangeN] == INVALID) {
                ++groupsCount;
            }
            else {
                auto found = memberMap.find(members[element.rangeN]);
                if (found->second > 1) --found->second;
                else memberMap.erase(found);
            }
            auto found = memberMap.lower_bound(element.val);
            if (found != memberMap.end() && found->first == element.val) ++found->second;
            else memberMap.emplace_hint(found, element.val, 1);
            members[element.rangeN] = element.val;
            pq.pop();
        }
        int minVal = memberMap.begin()->first;
        int maxVal = memberMap.rbegin()->first;

        while (!pq.empty()) {
            const inRange& element = pq.top();
            auto found = memberMap.find(members[element.rangeN]);
            if (found->second > 1) --found->second;
            else memberMap.erase(found);
            found = memberMap.lower_bound(element.val);
            if (found != memberMap.end() && found->first == element.val) ++found->second;
            else memberMap.emplace_hint(found, element.val, 1);
            members[element.rangeN] = element.val;
            pq.pop();
            int curMin = memberMap.begin()->first;
            int curMax = memberMap.rbegin()->first;
            if (curMax - curMin < maxVal - minVal || (curMax - curMin == maxVal - minVal && curMin < minVal)) {
                minVal = curMin;
                maxVal = curMax;
            }
        }
        return { minVal, maxVal };
    }
};