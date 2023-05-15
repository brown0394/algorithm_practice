#include <iostream>

typedef class jlist;
typedef struct jnode;

struct jnode{
    jnode* next;
    jnode* prev;
    int val;
};

class jlist{
private:
    jnode* begin;
    jnode* cur;
    int remWhich;
    int size;
    jnode* createNode(int val);
    void linkInBetween(jnode* a, jnode* b, jnode* oneInMid);
    void linkAB(jnode* a, jnode* b);
public:
    jlist(int num, int rem);

    int remove();
    ~jlist();

};

void jlist::linkInBetween(jnode* a, jnode* b, jnode* oneInMid) {
    a->next = oneInMid;
    oneInMid->next = b;
    b->prev = oneInMid;
    oneInMid->prev = a;
}

void jlist::linkAB(jnode* a, jnode* b) {
    a->next = b;
    b->prev = a;
}

jlist::jlist(int num, int rem): remWhich(rem-1), begin(nullptr),
 cur(nullptr), size(num){
    begin = createNode(1);
    begin->prev = begin;
    begin->next = begin;
    cur = begin;
    for (int i = 2; i <= num; ++i) {
        linkInBetween(begin->prev, begin, createNode(i));
    }
}
jlist::~jlist() {
    while(size) {
        --size;
        jnode* temp = cur->next;
        delete cur;
        cur = temp;
    }
}

int jlist::remove() {
    if ((this->size) == 0) return -1;
    --(this->size);
    int ret;
    if (size == 0) {
        ret = this->cur->val;
        delete this->cur;
    }
    else {
        for (int i = 0; i < this->remWhich; ++i) {
            this->cur = this->cur->next;
        }
        ret = this->cur->val;
        jnode* temp = this->cur->next;
        linkAB(this->cur->prev, this->cur->next);
        delete this->cur;
        this->cur = temp;
    }
    return ret;
}

jnode* jlist::createNode(int val) {
    jnode* ret = new jnode;
    ret->val = val;
    ret->next = nullptr;
    return ret;
}
int main() {
    int howMany, oneToRemove;
    scanf("%d %d", &howMany, &oneToRemove);

    jlist jl(howMany, oneToRemove);
    int retVal = jl.remove();
    printf("<%d", retVal);
    while (true) {
        retVal = jl.remove();
        if (retVal < 0) break;
        printf(", %d", retVal);
    }
    printf(">\n");
}
