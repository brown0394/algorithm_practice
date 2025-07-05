class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        int ii = 0;
        int size = arr.size();
        while (ii < size)
        {
            int seekTo = ii + arr[ii] - 1;
            if (seekTo < size && arr[seekTo] == arr[ii])
            {
                if ( seekTo + 1 == size || (seekTo + 1 < size && arr[seekTo + 1] != arr[ii]))
                    return arr[ii];
                else
                    ii = seekTo + 1;
            }
            while(ii + 1 < size && arr[ii] == arr[ii+1]) ++ii;
            ++ii;
        }
        return -1;
    }
};