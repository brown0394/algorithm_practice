#include <iostream>
#include <cstring>
int main() {
    int inputs;
    char buffer[55];
    int open, close;
    bool valid;
    scanf("%d", &inputs);
    for (int i = 0; i < inputs; ++i) {
        scanf("%s", buffer);
        open = 0;
        close = 0;
        valid = true;
        int size = strlen(buffer);
        for (int j = 0; j < size; ++j) {
            if (buffer[j] == '(') ++open;
            else ++close;
            if (close > open) {
                valid = false;
                break;
            }
        }
        if (valid && open == close) printf("YES\n");
        else printf("NO\n");
    }

}