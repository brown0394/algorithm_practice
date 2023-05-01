#include <iostream>
#include <cstring>

#define EMPTY -1
class deque {
private:
    int memSize;
    int mem[10000];
public:
    deque();
    void push_front(int elem);
    void push_back(int elem);
    int pop_front();
    int pop_back();
    int size();
    int empty();
    int front();
    int back();
};

deque::deque(): memSize(0), mem{0} {
}

void deque::push_front(int elem) {
    if (memSize) {
        memmove(&mem[1], mem, sizeof(int) * memSize);
    }
    mem[0] = elem;
    ++memSize;
}

void deque::push_back(int elem) {
    mem[memSize++] = elem;
}

int deque::pop_front() {
    if (!memSize) {
        return EMPTY;
    }
    int retval = mem[0];
    memmove(mem, &mem[1], sizeof(int) * --memSize);
    return retval;
}

int deque::pop_back() {
    if (!memSize) {
        return EMPTY;
    }
    return mem[--memSize];
}

int deque::size() {
    return memSize;
}

int deque::empty() {
    return memSize == 0;
}

int deque::front() {
    if (!memSize) {
        return EMPTY;
    }
    return mem[0];
}

int deque::back() {
    if (!memSize) {
        return EMPTY;
    }
    return mem[memSize-1];
}

int main() {
    deque dq;
    char command[15];
    int commands;
    int num;
    scanf("%d", &commands);
    for (int i = 0; i < commands; ++i) {
        scanf("%s", command);
        switch (command[0]) {
            case 'b' : {printf("%d\n", dq.back()); break;}
            case 'e' : {printf("%d\n", dq.empty()); break;}
            case 'f' : {printf("%d\n", dq.front()); break;}
            case 's' : {printf("%d\n", dq.size()); break;}
            default : {
                if (command[1] == 'u') {
                    scanf("%d", &num);
                    if (command[5] == 'b') {
                        dq.push_back(num);
                    }
                    else {
                        dq.push_front(num);
                    }
                }
                else {
                    if (command[4] == 'b') {
                        printf("%d\n", dq.pop_back());
                    }
                    else {
                        printf("%d\n", dq.pop_front());
                    }
                }
            }
        }
    }
}