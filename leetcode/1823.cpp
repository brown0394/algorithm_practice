class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> circle;
        for (int i = 1; i <= n; ++i) circle.push_back(i);
        auto it = circle.begin();
        while (n > 1) {
            int count = 1;
            while(count < k) {
                ++it;
                if (it == circle.end()) it = circle.begin();
                ++count;
            }
            it = circle.erase(it);
            if (it == circle.end()) it = circle.begin();
            --n;
        }
        return *it;
    }
};