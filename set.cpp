#include <iostream>

class bitSet {
private:
    int32_t space;

public:
    void add(int num);
    void remove(int num);
    void check(int num);
    void toggle(int num);
    void all();
    void empty();
};

void bitSet::add(int num) {
    space |= (1 << (num-1));
}

void bitSet::remove(int num) {
    int flag = 1 << (num-1);
    if (flag & space) {
        space ^= flag;
    }
}

void bitSet::check(int num) {
    int flag = 1 << (num-1);
    if (flag & space) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
}

void bitSet::toggle(int num) {
    space ^= (1 << (num-1));
}

void bitSet::all() {
    space = 1048575;
}

void bitSet::empty() {
    space = 0;
}

int main() {
    int N;
    bitSet bitset;
    scanf("%d", &N);
    char buf[10];
    int num = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%s", buf);

        if (buf[0] == 'e') {
            bitset.empty();
        }
        else if (buf[0] == 'a' && buf[1] == 'l') {
            bitset.all();
        }
        else {
            scanf("%d", &num);
            switch (buf[0]) {
                case 'a': {bitset.add(num); break;}
                case 'c': {bitset.check(num); break;}
                case 'r': {bitset.remove(num); break;}
                case 't': {bitset.toggle(num); break;}
            }
        }
    }
}