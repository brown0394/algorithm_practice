class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "011100110110001";
        --k;
        if (n < 4) return s[k];
        for (int i = 4; i < n - 1; ++i) {
            s.reserve(s.size() * 2 + 2);
            int j = s.size() - 1;
            s.push_back('1');
            for (; j >= 0; --j) {
                if (s[j] == '0') s.push_back('1');
                else s.push_back('0');
            }
            cout << s << '\n';
        }
        int mid = s.size();
        if (k < mid) return s[k];
        else if (k == mid) return '1';
        else {
            if (s[mid - (k - mid)] == '1') return '0';
            return '1';
        }

    }
};