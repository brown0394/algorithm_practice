class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        pair<int, int> one{1, 0};
        pair<int, int> two{0, 1};
        if (tops[0] == bottoms[0])
        {
            one.second = 1;
            two.first = 1;
        }
        int size = tops.size();
        for (int i = 1; i < size; ++i)
        {
            if (tops[0] < 7 && tops[i] == tops[0] || tops[0] == bottoms[i])
            {
                if (tops[i] == tops[0])
                    ++one.first;
                if (bottoms[i] == tops[0])
                    ++one.second;
            }
            else
                tops[0] = 10;
            if (bottoms[0] < 7 && tops[i] == bottoms[0] || bottoms[0] == bottoms[i])
            {
                if (tops[i] == bottoms[0])
                    ++two.first;
                if (bottoms[i] == bottoms[0])
                    ++two.second;
            }
            else
                bottoms[0] = 10;          
        }
        int ans = -1;
        if (tops[0] < 7)
            ans = min(size - one.first, size - one.second);
        if (bottoms[0] < 7)
        {
            int calc = min(size - two.first, size - two.second);
            if (ans == -1)
                ans = calc;
            else
                ans = min(ans, calc);
        }
        return ans;
    }
};