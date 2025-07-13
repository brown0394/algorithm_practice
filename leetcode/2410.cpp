class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end(), greater<int>());
        sort(trainers.begin(), trainers.end(), greater<int>());

        int pSize = players.size();
        int tSize = trainers.size();

        int i = 0, j = 0;
        int count = 0;
        while (i < pSize && j < tSize)
        {
            if (players[i] <= trainers[j])
            {
                ++count;
                ++i;
                ++j;
                continue;
            }
            ++i;
        }
        return count;
    }
};