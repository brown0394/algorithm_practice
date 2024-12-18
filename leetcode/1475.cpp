class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        stk.push(0);
        for (int i = 1, size = prices.size(); i < size; ++i) {
            while (!stk.empty() && prices[stk.top()] >= prices[i]) {
                prices[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        return prices;
    }
};