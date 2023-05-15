#include <iostream>
#include <algorithm>
#include <cstring>

struct {
    char elem[51];
}typedef wrapper;

bool compare(wrapper& a, wrapper& b) {
    int lenA = strlen(a.elem);
    int lenB = strlen(b.elem);
    if (lenA == lenB) {
        int i = 0;
        for (; i < lenA; ++i) {
            if (a.elem[i] != b.elem[i]) {
                break;
            }
        }
        if (i < lenA) {
            return a.elem[i] < b.elem[i];
        }
        return false;
    }
    return lenA < lenB;
}

int main() {
    int num;
    scanf("%d", &num);
    wrapper *arr = new wrapper[num];
    for (int i = 0; i < num; ++i) {
        scanf("%s", arr[i].elem);
    }
    std::sort(arr, arr+num, compare);
    wrapper* last = nullptr;
    for (int i = 0; i < num; ++i) {
        if (last != nullptr && !strcmp(arr[i].elem, last->elem)) {
            continue;
        }
        printf("%s\n", arr[i].elem);
        last = &arr[i];
    }
    delete[] arr;
}