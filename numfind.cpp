#include <iostream>
#include <map>

int main() {
    int end, in;
    std::map<int, short int> dictionary;

    scanf("%d", &end);

    for (int i = 0; i < end; ++i) {
        scanf("%d", &in);
        dictionary.insert(std::make_pair(in, 1));
    }

    scanf("%d", &end);
    for (int i = 0; i < end; ++i) {
        scanf("%d", &in);
        std::map<int, short int>::iterator found = dictionary.find(in);
        if (found == dictionary.end()) {
            printf("0\n");
        }
        else {
            printf("%d\n", found->second);
        }
    }
}


