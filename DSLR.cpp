#include <iostream>
#include <queue>
#include <cstring>


class node {
public:
	unsigned short int num;
	char* commands;
	node(unsigned short int num, char* str, char command);
	~node();
};

node::node(unsigned short int p_num, char* p_commands, char p_command) : num(p_num), commands(nullptr) {
	int len = strlen(p_commands) + 2;
	commands = new char[len];
	if (len > 2) {
		strcpy(commands, p_commands);
	}
	commands[len - 2] = p_command;
	commands[len - 1] = '\0';
}
node:: ~node() {
	delete[] commands;
}

class minCommandCalculator {
private:
	unsigned short int D(unsigned short int num);
	unsigned short int S(unsigned short int num);
	unsigned short int L(unsigned short int num);
	unsigned short int R(unsigned short int num);
	char addChildren(unsigned short int target);
	std::queue<node*> q;
	bool alreadyVisited[10000];
	void visitCheckAndPush(node* cur, unsigned int calcVal, char command);
public:
	void calcMinCombination(unsigned short int intitialReg, unsigned short int target);
};


inline unsigned short int minCommandCalculator::D(unsigned short int num) {
	return (num << 1) % 10000;
}

inline unsigned short int minCommandCalculator::S(unsigned short int num) {
	if (num) {
		return --num;
	}
	return 9999;
}

inline unsigned short int minCommandCalculator::L(unsigned short int num) {
	return ((num % 1000) * 10) + num / 1000;
}

inline unsigned short int minCommandCalculator::R(unsigned short int num) {
	int rot = num % 10;
	return (num % 10) * 1000 + (num / 10);
}

inline void minCommandCalculator::visitCheckAndPush(node* cur, unsigned int calcVal, char command) {
	if (!alreadyVisited[calcVal]) {
		q.push(new node(calcVal, cur->commands, command));
		alreadyVisited[calcVal] = true;
	}
}

char minCommandCalculator::addChildren(unsigned short int target) {
	node* cur = q.front();
	unsigned short int calcD = D(cur->num);
	if (calcD == target) return 'D';
	unsigned short int calcS = S(cur->num);
	if (calcS == target) return 'S';
	unsigned short int calcL = L(cur->num);
	if (calcL == target) return 'L';
	unsigned short int calcR = R(cur->num);
	if (calcR == target) return 'R';
	visitCheckAndPush(cur, calcD, 'D');
	visitCheckAndPush(cur, calcS, 'S');
	visitCheckAndPush(cur, calcL, 'L');
	visitCheckAndPush(cur, calcR, 'R');
	delete cur;
	q.pop();
	return '\0';
}

void minCommandCalculator::calcMinCombination(unsigned short int initialReg, unsigned short int target) {
	char init[1] = "";
	q.push(new node(initialReg, init, '\0'));
	char last = '\0';
	while (last == '\0') {
		last = addChildren(target);
	}
	node* temp = q.front();
	for (char* iter = temp->commands; *iter != '\0'; ++iter) {
		printf("%c", *iter);
	}
	while (!q.empty()) {
		delete q.front();
		q.pop();
	}
	printf("%c\n", last);
	std::fill_n(alreadyVisited, 10000, false);
}

int main() {
	minCommandCalculator calc;
	int testCases;
	scanf("%d", &testCases);

	unsigned short int initialReg;
	unsigned short int target;
	for (int i = 0; i < testCases; ++i) {
		scanf("%hu %hu", &initialReg, &target);
		calc.calcMinCombination(initialReg, target);
	}
}