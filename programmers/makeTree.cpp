#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
struct nodeLoc {
    int nodeNum;
    int x;
    int y;
};

struct node {
    int num;
    int x; 
    node* leftChild;
    node* rightChild;
};

class tree {
private:
    node* root;
    node* createNode(int num, int x);
public:
    tree(vector<nodeLoc>& nodes);
    void getPathOrder(vector<vector<int>>& answer);
    ~tree();
};

tree::~tree() {
    if (root != nullptr) {
        stack<pair<node*, short int>> stk;
        node* cur = root;
        if (root->leftChild != nullptr) {
            stk.push(make_pair(root, 1));
            cur = root->leftChild;
        }
        else if (root->rightChild != nullptr) {
            stk.push(make_pair(root, 2));
            cur = root->rightChild;
        }
        else {
            delete root;
            return;
        }
        
        short int nextStep = 0;
        while (true) {
            if (nextStep < 2) {
                if (nextStep == 0 && cur->leftChild != nullptr) {
                    stk.push(make_pair(cur, 1));
                    nextStep = 0;
                    cur = cur->leftChild;
                    continue;
                }
                if (cur->rightChild != nullptr) {
                    stk.push(make_pair(cur, 2));
                    nextStep = 0;
                    cur = cur->rightChild;
                    continue;
                }
            }
            if (cur == root) break;
            delete cur;
            cur = stk.top().first;
            nextStep = stk.top().second;
            stk.pop();
        }
        delete root;
    }
}

tree::tree(vector<nodeLoc>& nodes) {
    root = createNode(nodes[0].nodeNum, nodes[0].x);
    node* cur;

    for (auto it = nodes.begin()+1; it != nodes.end(); ++it) {
        cur = root;
        while (true) {
            if (it->x < cur->x) {
                if (cur->leftChild != nullptr) {
                    cur = cur->leftChild;
                }
                else {
                    cur->leftChild = createNode(it->nodeNum, it->x);
                    break;
                }
            }
            else {
                if (cur->rightChild != nullptr) {
                    cur = cur->rightChild;
                }
                else {
                    cur->rightChild = createNode(it->nodeNum, it->x);
                    break;
                }
            }
        }
    }
}

void tree::getPathOrder(vector<vector<int>>& answer) {
    if (root != nullptr) {
        stack<pair<node*, short int>> stk;
        node* cur = root;
        if (root->leftChild != nullptr) {
            stk.push(make_pair(root, 1));
            cur = root->leftChild;
        }
        else if (root->rightChild != nullptr) {
            stk.push(make_pair(root, 2));
            cur = root->rightChild;
        }
        else {
            answer[0].push_back(root->num);
            answer[1].push_back(root->num);
            return;
        }
        answer[0].push_back(root->num);
        short int nextStep = 0;
        while (true) {
            if (nextStep < 2) {
                if (nextStep == 0 && cur->leftChild != nullptr) {
                    stk.push(make_pair(cur, 1));
                    answer[0].push_back(cur->num);
                    nextStep = 0;
                    cur = cur->leftChild;
                    continue;
                }
                if (cur->rightChild != nullptr) {
                    stk.push(make_pair(cur, 2));
                    if (!nextStep) {
                        answer[0].push_back(cur->num);
                    }
                    nextStep = 0;
                    cur = cur->rightChild;
                    continue;
                }
            }
            if (cur == root) break;
            if (!nextStep) {
                answer[0].push_back(cur->num);
            }
            answer[1].push_back(cur->num);
            cur = stk.top().first;
            nextStep = stk.top().second;
            stk.pop();
        }
        answer[1].push_back(cur->num);
    }
}

node* tree::createNode(int num, int x) {
    node* newNode = new node;
    newNode->num = num;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    newNode->x = x;
    return newNode;
}

bool sortStandard(nodeLoc& one, nodeLoc& two) {
    if (one.y == two.y) {
        return one.x < two.x;
    }
    return one.y > two.y;
}

void print(vector<nodeLoc>& nodes) {
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        printf("%d : %d %d\n", it->nodeNum, it->x, it->y);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<nodeLoc> nodes;
    nodes.reserve(nodeinfo.size());
    for (int i = 0; i < nodeinfo.size(); ++i) {
        nodes.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
    }
    sort(nodes.begin(), nodes.end(), sortStandard);
    tree pathTree(nodes);
    pathTree.getPathOrder(answer);
    return answer;
}

int main() {
    vector<vector<int>> nodeinfo {{5, 3}, { 2, 1 }};
    vector<vector<int>> answer = solution(nodeinfo);
    for (auto it = answer.begin(); it != answer.end(); ++it) {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
            printf("%d ", *it2);
        }
        putchar('\n');
    }
}