#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

typedef struct  node;
struct node {
	node** children;
	int num;
	std::vector <char> command;
};


class minCommandCalculator {
private :
	int D(int num);
	int S(int num);
	int L(int num);
	int R(int num);
	node* getNewNode(node* parent, int num, char command);
	char addChildren(node* cur, int target);
	node* root;
public:
	void calcMinCombination(int intitialReg, int target);
	minCommandCalculator();
	~minCommandCalculator();
};

minCommandCalculator::minCommandCalculator() : root(nullptr) {
}

minCommandCalculator::~minCommandCalculator() {
	if (root != nullptr) {
		std::queue<node*> q;
		node* cur = root;
		node* temp;
		while (!q.empty()) {
			temp = cur;
			for (int i = 0; i < 4; ++i) {
				q.push(cur->children[i]);
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
	newNode->children = new node * [4] {nullptr};
	newNode->num = num;
	if (parent != nullptr) {
		std::copy(parent->command.begin(), parent->command.end(), std::back_inserter(newNode->command));
		newNode->command.push_back(command);
	}
	return newNode;
}

char minCommandCalculator::addChildren(node* cur, int target) {
	int calcD = D(cur->num);
	if (calcD == target) return 'D';
	int calcS = S(cur->num);
	if (calcS == target) return 'S';
	int calcL = L(cur->num);
	if (calcL == target) return 'L';
	int calcR = R(cur->num);
	if (calcR == target) return 'R';

	cur->children[0] = getNewNode(cur, calcD, 'D');
	cur->children[1] = getNewNode(cur, calcS, 'S');
	cur->children[2] = getNewNode(cur, calcL, 'L');
	cur->children[3] = getNewNode(cur, calcR, 'R');
	return '\0';
}

void minCommandCalculator::calcMinCombination(int intitialReg, int target) {
	node* cur;
	node* temp;
	std::queue<node*> q;
	root = getNewNode(nullptr, intitialReg, '\0');
	cur = root;
	char last;
	while (true) {
		last = addChildren(cur, target);
		if (last != '\0') {
			break;
		}
		for (int i = 0; i < 4; ++i) {
			q.push(cur->children[i]);
		}
		temp = cur;
		cur = q.front();
		delete temp;
		q.pop();
	}
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		delete temp;
	}
	for (auto iter = cur->command.begin(); iter != cur->command.end(); ++iter) {
		printf("%c", *iter);
	}
	printf("%c\n", last);
	delete cur;
	root = nullptr;
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