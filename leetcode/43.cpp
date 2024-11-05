class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string ans;
        int len2 = num2.size();
        int carry = 0;
        int cur = 0;
        for (int i = num1.size() - 1; i >= 0; --i) {
            int idx = cur++;
            if (num1[i] == '0') {
                if (idx >= ans.size()) ans.push_back(0);
                continue;
            }
            carry = 0;
            for (int j = len2-1; j >= 0; --j) {
                if (idx >= ans.size()) ans.push_back(carry);
                else ans[idx] += carry;
                ans[idx] += (num1[i] - '0') * (num2[j] - '0');
                carry = ans[idx] / 10;
                ans[idx] = ans[idx] % 10;
                ++idx;
            }
            while (carry) {
                if (idx >= ans.size()) ans.push_back(carry);
                else ans[idx] += carry;
                carry = (ans[idx] / 10);
                ans[idx] = (ans[idx] % 10);
                ++idx;
            }
        }
        int idx = ans.size()-1;
        string reversed;
        reversed.resize(idx+1);
        for (int i = 0, len = ans.size(); i < len; ++i) {
            reversed[idx--] = ans[i] + '0';
        }
        return reversed;
    }
};