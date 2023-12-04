#include <iostream>

class node {
public:
	node* left;
	node* right;
	int num;
	~node();
	node(int p_num);
};

node::~node() {
	if (left) delete left;
	if (right) delete right;
	printf("%d\n", num);
}

node::node(int p_num) : num(p_num), left(nullptr), right(nullptr) {}

class bst {
private:
	node* root;

public:
	~bst();
	bst();
};

bst::~bst() {
	if (root) {
		delete root;
	}
}

bst::bst() {
	int in;
	scanf("%d", &in);
	root = new node(in);
	node* cur;
	while (scanf("%d", &in) != EOF) {
		cur = root;
		while (true) {
			if (in < cur->num) {
				if (cur->left == nullptr) {
					cur->left = new node(in);
					break;
				}
				else {
					cur = cur->left;
				}
			}
			else {
				if (cur->right == nullptr) {
					cur->right = new node(in);
					delete cur->left;
					cur->left = nullptr;
					break;
				}
				else {
					cur = cur->right;
				}
			}
		}
	}
}


int main() {
	bst tree;
}