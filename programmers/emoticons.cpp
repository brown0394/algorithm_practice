#include <string>
#include <vector>
#include <stack>


using namespace std;

struct node {
    int emoticonIdx;
    int discountIdx;
    int* route;
};

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2, 0);
    vector<float> discounts{0.6, 0.7, 0.8, 0.9};
    vector<float> discountRates{40, 30, 20, 10};
    stack<node> stk;
    
    vector<int> userConsumed(users.size(), 0);

    int emoticonIdx;
    int sum;
    int* route;
    int subscribers;
    int size = emoticons.size() - 1;
    int maxSubscribers = 0;
    int maxSum = 0;
    stk.push(node{ 0, -1, new int[size + 1] {0} });
    while (!stk.empty()) {
        emoticonIdx = stk.top().emoticonIdx;
        route = stk.top().route;
        if (emoticonIdx == size) {
            sum = 0;
            subscribers = 0;
            for (int i = 0; i < users.size(); ++i) {
                userConsumed[i] = 0;
                for (int j = 0; j < emoticons.size(); ++j) {
                    if (discountRates[route[j]] >= users[i][0]) {
                        int charge = (emoticons[j] * discounts[route[j]]);
                        userConsumed[i] += charge;
                        sum += charge;
                    }
                }
                if (userConsumed[i] >= users[i][1]) {
                    sum -= userConsumed[i];
                    ++subscribers;
                }
            }
            if (maxSubscribers > subscribers || (maxSubscribers == subscribers && sum > maxSum)) {
                maxSum = sum;
                maxSubscribers = subscribers;
            }
            route[size] = 0;
            stk.pop();
        }
        if (stk.top().discountIdx < 3) {
            ++stk.top().discountIdx;
            route[emoticonIdx + 1] = stk.top().discountIdx;
            stk.push(node{emoticonIdx+1 , stk.top().discountIdx, route})
        }
    }


    answer[0] = lastSubscribers;
    answer[1] = lastSum;
    return answer;
}
int main() {
    //vector<vector<int>> users{{40, 10000}, { 25, 10000 }};
    vector<vector<int>> users{{40, 2900}, { 23, 10000 }, { 11, 5200 }, { 5, 5900 }, { 40, 3100 }, { 27, 9200 }, { 32, 6900 }};
    //vector<int> emoticons{7000, 9000};
    vector<int> emoticons{1300, 1500, 1600, 4900};
    vector<int> answer = solution(users, emoticons);
    printf("%d %d\n", answer[0], answer[1]);
}