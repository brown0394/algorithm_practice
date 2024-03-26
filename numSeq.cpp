#include <iostream>
#include <string>

void addOne(std::string& str) {
    int idx = 0;
    while (idx < str.size()) {
        if (str[idx] == '9') str[idx++] = '0';
        else {
            ++str[idx];
            return;
        }
    }
    str.push_back('1');
}

int main() {
    std::string numSeq;
    std::cin >> numSeq;
    
    std::string num{"0"};

    for (int i = 0, len = numSeq.size(); i < len; ++i) {
        bool same = false;
        while (!same) {
            addOne(num);
            int count = 0;
            for (int j = num.size() - 1; j >= 0; --j) {
                if (num[j] == numSeq[i]) {
                    same = true;
                    count = 1;
                    int idx = 1;
                    for (int k = j - 1; k >= 0; --k) {
                        if (i + idx >= len) break;
                        if (num[k] == numSeq[i + idx]) {
                            ++count;
                        }
                        ++idx;
                    }
                }
            }
            if (same) i += count - 1;
        }
    }
    for (int j = num.size() - 1; j >= 0; --j) {
        printf("%c", num[j]);
    }
    printf("\n");
}