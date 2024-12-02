class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size()-1;
        if (!last) return true;
        stack<int> stk;
        stk.push(0);
        vector<bool> visited(last+1);
        while (!stk.empty()) {
            int cur = stk.top();
            stk.pop();
            for (int i = 1; i <= nums[cur]; ++i) {
                if (cur + i >= last) return true;
                if (nums[cur + i] && !visited[cur+i]) {
                    visited[cur+i] = true;
                    stk.push(cur+i);
                }
                
            }
        }
        return false;
    }
};