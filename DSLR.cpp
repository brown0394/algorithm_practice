#include <iostream>
#include <vector>
#include <queue>

typedef struct  node;
struct node {
	std::vector<node*> children;
	node* parent;
	int num;
	char command;
};


class minCommandCalculator {
private :
	int D(int num);
	int S(int num);
	int L(int num);
	int R(int num);
	node* getNewNode(node* parent, int num, char command);
	void addChildren(node* cur, bool isAlreadCreated);
	std::vector<char> answer;
	node* root;
public:
	void calcMinCombination(int intitialReg, int target);
	minCommandCalculator();
	~minCommandCalculator();
};

minCommandCalculator::minCommandCalculator() : root(nullptr) {
	answer.reserve(100);
}

minCommandCalculator::~minCommandCalculator() {
	if (root != nullptr) {
		std::queue<node*> q;
		node* cur = root;
		node* temp;
		while (!q.empty()) {
			temp = cur;
			for (auto iter = cur->children.begin(); iter != cur->children.end(); ++iter) {
				q.push(*iter);
			}
			cur = q.front();
			q.pop();
			delete temp;
		}
	}
}

int minCommandCalculator::D(int num) {
	return (num << 1) % 10000;
}

int minCommandCalculator::S(int num) {
	if (num) {
		return --num;
	}
	return 9999;
}

int minCommandCalculator::L(int num) {
	return ((num % 1000) * 10) + num / 1000;
}

int minCommandCalculator::R(int num) {
	int rot = num % 10;
	return (num % 10) * 1000 + (num / 10);
}

node* minCommandCalculator::getNewNode(node* parent, int num, char command) {
	node* newNode = new node;
	newNode->parent = parent;
	newNode->children.reserve(4);
	newNode->num = num;
	newNode->command = command;
	return newNode;
}

void minCommandCalculator::addChildren(node* cur, bool isAlreadCreated) {
	if (isAlreadCreated) {
		cur->children[0]->num = D(cur->num);
		cur->children[1]->num = S(cur->num);
		cur->children[2]->num = L(cur->num);
		cur->children[3]->num = R(cur->num);
	}
	else {
		cur->children.push_back(getNewNode(cur, D(cur->num), 'D'));
		cur->children.push_back(getNewNode(cur, S(cur->num), 'S'));
		cur->children.push_back(getNewNode(cur, L(cur->num), 'L'));
		cur->children.push_back(getNewNode(cur, R(cur->num), 'R'));
	}
}

void minCommandCalculator::calcMinCombination(int intitialReg, int target) {
	node* cur;
	std::queue<node*> q;
	if (root == nullptr) {
		root = getNewNode(nullptr, intitialReg, '\0');
	}
	else {
		root->num = intitialReg;
	}
	cur = root;
	while (cur->num != target) {
		addChildren(cur, !cur->children.empty());
		for (int i = 0; i < 4; ++i) {
			q.push(cur->children[i]);
		}
		cur = q.front();
		q.pop();
	}
	while (cur != root) {
		answer.push_back(cur->command);
		cur = cur->parent;
	}
	for (auto iter = answer.rbegin(); iter != answer.rend(); ++iter) {
		printf("%c", *iter);
	}
	printf("\n");
	answer.clear();
	
}

int main() {
	minCommandCalculator calc;
	int testCases;
	scanf_s("%d", &testCases);

	int initialReg;
	int target;
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d %d", &initialReg, &target);
		calc.calcMinCombination(initialReg, target);
	}
}