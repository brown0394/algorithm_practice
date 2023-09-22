#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct nodeLoc {
    int nodeNum;
    int x;
    int y;
};

struct node {
    int num;
    node* leftChild;
    node* rightChild;
    node* next;
};

class tree {
private:
    node* root;
    node* createNode(int num);
public:
    tree(vector<nodeLoc>& nodes, vector<vector<int>>& nodeinfo);
};
tree::tree(vector<nodeLoc>& nodes, vector<vector<int>>& nodeinfo) {
    root = createNode(nodes[0].nodeNum);
    root->next = root;
    node* lastlast = nullptr;
    node* last = root;
    node* lastCurNode = last;
    int len = nodeinfo.size();

    int curIdx = 1;

    while (curIdx < len) {
        if (curIdx > 1 && nodes[curIdx].y < nodes[curIdx - 1].y) {
            lastlast = last->next;
            last = 
        }
        
    }
}

node* tree::createNode(int num) {
    node* newNode = new node;
    newNode->num = num;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    newNode->next = nullptr;
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
    vector<vector<int>> answer;
    vector<nodeLoc> nodes;
    nodes.reserve(nodeinfo.size());
    for (int i = 0; i < nodeinfo.size(); ++i) {
        nodes.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
    }
    sort(nodes.begin(), nodes.end(), sortStandard);


    return answer;
}