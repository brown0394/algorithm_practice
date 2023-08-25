#include <iostream>
#include <vector>
#include <queue>

struct node {
    node* next;
    int num;
};

struct head {
    node* next;
    node* last;
};

node* getNewnode(short int num) {
    node* newNode = new node;
    newNode->next = nullptr;
    newNode->num = num;
    return newNode;
}

void checkAndAddNode(head& h, short int num) {
    node* newnode;
    if (h.next == nullptr) {
        h.next = getNewnode(num);
        h.last = h.next;
    }
    else {
        h.last->next = getNewnode(num);
        h.last = h.last->next;
    }
}

int main() {
    int numberOfNodes;
    int connections;
    scanf("%d", &numberOfNodes);
    scanf("%d", &connections);
    std::vector<bool> countChecks(numberOfNodes+1);
    std::vector<head> connectedComputer(numberOfNodes+1);
    std::queue<short int> q;
    int com1, com2;
    for (int i = 0; i < connections; ++i) {
        scanf("%d %d", &com1, &com2);
        checkAndAddNode(connectedComputer[com1], com2);
        checkAndAddNode(connectedComputer[com2], com1);
    }

    
    node* cur = connectedComputer[1].next;
    countChecks[1] = true;
    int count = 0;
    while (true) {
        if (cur != nullptr) {
            if (!countChecks[cur->num]) {
                countChecks[cur->num] = true;
                q.push(cur->num);
            }
            cur = cur->next;
        }
        else {
            if (q.empty()) {
                break;
            }
            cur = connectedComputer[q.front()].next;
            ++count;
            q.pop();
        }
    }
    printf("%d\n", count);
}