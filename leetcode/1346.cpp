class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0, len = arr.size()-1; i < len; ++i) {
            vector<int>::iterator it;
            int dv = arr[i] << 1;
            if (arr[i] < 0) it = lower_bound(arr.begin(), arr.begin() + i, dv);
            else it = lower_bound(arr.begin()+i+1, arr.end(), dv);
            if (it != arr.end() && *it == dv) {
                cout << arr[i] << " " << dv << endl;
                return true;
            }
        }
        return false;
    }
};