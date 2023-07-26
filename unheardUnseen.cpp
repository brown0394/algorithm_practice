#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int unheard, unseen;
    scanf("%d %d", &unheard, &unseen);

    std::set<std::string> unheardArr;
    char name[21];
    for (int i = 0; i < unheard; ++i) {
        scanf("%s", name);
        unheardArr.insert(name);
    }


    std::vector<std::string> result;
    for (int i = 0; i < unseen; ++i) {
        scanf("%s", name);
        auto found = unheardArr.find(name);
        if (found != unheardArr.end()) {
            result.push_back(*found);
        }
    }
    if (result.size()) {
        printf("%d\n", result.size());
        std::sort(result.begin(), result.end());
        for (auto it = result.begin(); it != result.end(); ++it) {
            printf("%s\n", it->c_str());
        }
    }
    else {
        printf("0\n");
    }

}