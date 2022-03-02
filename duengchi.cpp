#include <iostream>
#include <vector>

typedef struct Node Node;

struct Node {
    int weight;
    int height;
    int rank;
    Node* next;
};

int main() {
    int num = 0;
    std::cin >> num;

    Node** arr = new Node*[num];
    std::vector<Node*> v;
    

    for (int i = 0; i < num; ++i) {
        Node* newnode = new Node;
        std::cin >> newnode->weight >> newnode->height;
        newnode->next = nullptr;
        arr[i] = newnode;
        if (v.empty()) {
            v.push_back(arr[i]);
        }
        else {
            bool notfound = true;
            for (std::vector<Node*>::iterator j = v.begin(); j != v.end(); ++j) {
                if ((*j)->weight > arr[i]->weight && (*j)->height > arr[i]->height) {
                    continue;
                }
                else if ((*j)->weight < arr[i]->weight && (*j)->height < arr[i]->height) {
                    v.insert(j, arr[i]);
                    notfound = false;
                    break;
                }
                else {
                    Node* cur = (*j);
                    while(cur->next != nullptr) {
                        if (cur->weight > arr[i]->weight && cur->height > arr[i]->height) continue;
                        cur = cur->next;
                    }
                    if (cur->weight > arr[i]->weight && cur->height > arr[i]->height) continue;
                    cur->next = arr[i];
                    notfound = false;
                    break;
                }
            }
            if(notfound) {
                v.push_back(arr[i]);
            }
        }
    }
    int count = 1;
    int subcount;
    for (std::vector<Node*>::iterator j = v.begin(); j != v.end(); ++j) {
        Node* cur = *j;
        subcount = 0;
        while(cur != nullptr) {
            ++subcount;
            cur->rank = count;
            cur = cur->next;
        }
        count += subcount;
    }

    for (int i = 0; i < num; ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << arr[i]->rank;
    }
    std::cout << std::endl;
    delete[] arr;//접근이 틀림. 무지성으로 보다 큰 것의 갯수를 새는것임.
}