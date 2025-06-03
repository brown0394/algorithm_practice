class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;
        
        int i = a.size()-1;
        int j = b.size()-1;
        string ans;
        ans.resize(max(i , j) + 1);
        int cur = ans.size()-1;

        while (i >= 0 && j >= 0)
        {
            char result = (a[i] - '0') + (b[j] - '0') + carry + '0';
            if (result > '1')
            {
                carry = true;
                if (result == '2')
                    result = '0';
                else
                    result = '1';
            }
            else
                carry = false;
            ans[cur--] = result;
            --i;
            --j;
        }
        string* pt;
        if (i >= 0)
            pt = &a;
        else
        {
            pt = &b;
            i = j;
        }
        while (i >= 0)
        {
            char result = (*pt)[i] + carry;
            if (result > '1')
            {
                carry = true;
                result = '0';
            }
            else
                carry = false;
            ans[cur--] = result;
            --i;
        }
        if (carry)
            return "1" + ans;
        return ans;
    }
};