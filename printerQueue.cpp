#include <algorithm>
#include <iostream>
#include <deque>

typedef struct {
    int num;
    bool target;
}data;

bool compare(data& one, data& two) {
    return one.num < two.num;
}

int main() {
    int numOfCases;
    scanf("%d", &numOfCases);
    int numOfInputs, targetPos, qinput;
    for (int i = 0; i < numOfCases; ++i) {
        scanf("%d %d", &numOfInputs, &targetPos);
        std::deque<data> arr;
        for (int j = 0; j < numOfInputs; ++j) {
            scanf("%d", &qinput);
            arr.push_back(data{qinput, false});
            if (j == targetPos) {
                arr.back().target = true;
            }
        }
        std::deque<data> arr2(arr);
        std::sort(arr2.begin(), arr2.end(), compare);
        std::deque<data>::reverse_iterator rit = arr2.rbegin();
        int thPrint = 1;
        while (true){//rit != arr2.rend()) {
            if (arr.front().num == rit->num) {
                if (arr.front().target) {
                    printf("%d\n", thPrint);
                    break;
                }
                ++rit;
                ++thPrint;
            }
            else {
                arr.push_back(arr.front());
            }
            arr.pop_front();
        }
    }
}