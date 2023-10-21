#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sortStd(vector<int>&one , vector<int>& two) {
    return one[0] > two[0];
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<float> discounts(emoticons.size(), 0.4f);
    //sort(users.begin(), users.end(), sortStd);
    int sum = 0;
    int subscriber = 0;
    vector<int> userConsumed(users.size(), 0);
    for (int i = 0; i < users.size(); ++i) {
        if (users[i][0] >= 40)
        for (int j = 0; j < emoticons.size(); ++j) {
            int charge = (emoticons[j] * 0.4);
            userConsumed[i] += charge;
            sum += charge;
        }
        if (users[i][1] <= userConsumed[i]) {
            ++subscriber;
            sum -= userConsumed[i];
        }
    }
    for (int i = 0; i < emoticons.size(); ++i) {
        for (int j = 0; j < 4; ++i) {
            int discountSubtract = j * 10;
            for (int k = 0; k < users.size(); ++k) {
                
            }
        }
    }
    printf("%d\n", users[0][0]);
    return answer;
}