#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

int main() {
    std::set<int> numSet;
    int num, in;
    scanf("%d", &num);

    for (int i = 0; i < num; ++i) {
        scanf("%d", &in);
        numSet.insert(in);
    }
    std::copy(numSet.begin(), numSet.end(), std::ostream_iterator<int>(std::cout, "\n"));

}