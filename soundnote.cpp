#include <iostream>
#define ASCEND 0
#define DESCEND 1
#define MIXED 2


int main(void) {
    int order;
    int last = 0;
    int cur;
    for (int i = 0; i < 8; ++i) {
        std::cin >> cur;
        if (last == 0) {
            if (cur == 8) order = DESCEND;
            else order = ASCEND;
            last = cur;
            continue;
        }
        if ((order == ASCEND && (cur - last) < 1)
        || (order == DESCEND && (last - cur) < 1)) {
            order = MIXED;
            break;
        }
        last = cur;
    }
    switch(order) {
        case ASCEND: {std::cout << "ascending" << std::endl; break;}
        case DESCEND: {std::cout << "descending" << std::endl; break;}
        case MIXED: {std::cout << "mixed" << std::endl; break;}
    }
}