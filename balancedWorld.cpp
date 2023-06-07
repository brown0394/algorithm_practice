#include <iostream>

int main() {
    char str[101];
    char storage[102];
    int storageIdx;
    bool balance;
    storage[0] = '\0';
    while (true) {
        scanf("%[^\n]s", str);
        getchar();
        if (str[0] == '.') break;
        balance = true;
        storageIdx = 1;
        for (int i = 0; str[i] != '.'; ++i) {
            switch (str[i]) {
                case '(': {
                    storage[storageIdx++] = '(';
                    break;
                }
                case ')': {
                    if (storage[storageIdx-1] == '(') {
                        --storageIdx;
                    }
                    else {
                        balance = false;
                        str[i+1] = '.';
                    }
                    break;
                }
                case '[': {
                    storage[storageIdx++] = '[';
                    break;
                }
                case ']': {
                    if (storage[storageIdx-1] == '[') {
                        --storageIdx;
                    }
                    else {
                        balance = false;
                        str[i+1] = '.';
                    }
                    break;
                }
            }
        }
        if (balance && storageIdx == 1) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
}