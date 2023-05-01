#include <iostream>

#define EMPTY -1
class que {
private:
    int memSize;
    int mem[10000];
public:
    que();
    void push(int elem);
    int pop();
    int size();
    int empty();
    int top();
};

que::que(): memSize(0), mem{0} {
}

void que::push(int elem) {
    mem[memSize++] = elem;
}

int que::pop() {
    if (!memSize) {
        return EMPTY;
    }
    return mem[--memSize];
}

int que::size() {
    return memSize;
}

int que::empty() {
    return memSize == 0;
}

int que::top() {
    if (!memSize) {
        return EMPTY;
    }
    return mem[memSize-1];
}

int main() {
    que dq;
    char command[15];
    int commands;
    int num;
    scanf("%d", &commands);
    for (int i = 0; i < commands; ++i) {
        scanf("%s", command);
        switch (command[0]) {
            case 'e' : {printf("%d\n", dq.empty()); break;}
            case 's' : {printf("%d\n", dq.size()); break;}
            case 't' : {printf("%d\n", dq.top()); break;}
            default : {
                if (command[1] == 'u') {
                    scanf("%d", &num);
                    dq.push(num);
                }
                else {
                    printf("%d\n", dq.pop());
                }
            }
        }
    }
}