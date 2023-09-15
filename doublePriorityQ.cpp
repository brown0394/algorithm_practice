#include <iostream>
#include <vector>
#include <map>
#include <set>

class priorityQ {
private:
	std::vector<int> pq;
	std::vector<int> mq;
	void swap(int& one, int& two);
	int removeLeafFromQ(bool isMaxQ, int num);
	void popTop(bool isMaxQ);
	bool compare(bool isMaxQ, int one, int two);
public:
	void insert(int num);
	void popGreatest();
	void popSmallest();
	void print();
	void clear();
};

void priorityQ::clear() {
	pq.clear();
	mq.clear();
}

inline void priorityQ::swap(int& one, int& two) {
	int temp = one;
	one = two;
	two = temp;
}

void priorityQ::insert(int num) {
	pq.push_back(num);
	int len = pq.size();
	int idxToCompare;
	while (len > 1) {
		idxToCompare = len >> 1;
		if (pq[idxToCompare - 1] < num) {
			swap(pq[len - 1], pq[idxToCompare - 1]);
			len = idxToCompare;
		}
		else {
			break;
		}
	}
	mq.push_back(num);
	len = mq.size();
	while (len > 1) {
		idxToCompare = len >> 1;
		if (mq[idxToCompare - 1] > num) {
			swap(mq[len - 1], mq[idxToCompare - 1]);
			len = idxToCompare;
		}
		else {
			break;
		}
	}
}

void priorityQ::popGreatest() {
	if (pq.empty()) return;
	removeLeafFromQ(false, pq[0]);
	popTop(true);
}

void priorityQ::popSmallest() {
	if (mq.empty()) return;
	removeLeafFromQ(true, mq[0]);
	popTop(false);
}

bool priorityQ::compare(bool isMaxQ, int one, int two) {
	if (isMaxQ) {
		return one > two;
	}
	return one < two;
}

void priorityQ::popTop(bool isMaxQ) {
	std::vector<int>* priorityq;
	if (isMaxQ) {
		priorityq = &pq;
	}
	else {
		priorityq = &mq;
	}
	int idx = 1;
	(*priorityq)[idx - 1] = (*priorityq)[priorityq->size() - 1];
	priorityq->pop_back();
	int len = priorityq->size();
	int childToSwap;
	int idxToCompare;
	idxToCompare = idx << 1;
	while (idxToCompare <= len) {
		if (idxToCompare + 1 > len || compare(isMaxQ, (*priorityq)[idxToCompare - 1], (*priorityq)[idxToCompare])) { //if it does not have right child or left child is better.
			childToSwap = idxToCompare;//left child
		}
		else {
			childToSwap = idxToCompare + 1;//right child
		}
		if (compare(isMaxQ, (*priorityq)[childToSwap - 1], (*priorityq)[idx - 1])) {//if its child is better
			swap((*priorityq)[childToSwap - 1], (*priorityq)[idx - 1]);
			idx = childToSwap;
		}
		else {
			break;
		}
		idxToCompare = idx << 1;
	}
}
int priorityQ::removeLeafFromQ(bool isMaxQ, int num) {
	std::vector<int>* priorityq;
	if (isMaxQ) {
		priorityq = &pq;
	}
	else {
		priorityq = &mq;
	}
	int idx;
	int size = priorityq->size();
	for (int i = size - 1; i >= 0; --i) {
		if ((*priorityq)[i] == num) {
			idx = i + 1;
			break;
		}
	}
	if (idx == size) {
		priorityq->pop_back();
		return num;
	}
	(*priorityq)[idx - 1] = (*priorityq)[size - 1];
	priorityq->pop_back();
	int greaterChild;
	int idxToCompare;
	while (idx > 1) {
		idxToCompare = idx >> 1;//parent
		if (compare(isMaxQ, (*priorityq)[idx - 1], (*priorityq)[idxToCompare - 1])) {//if child is better than parent
			swap((*priorityq)[idx - 1], (*priorityq)[idxToCompare - 1]);
			idx = idxToCompare;
		}
		else {
			break;
		}
	}
	return num;
}


void priorityQ::print() {
	if (pq.empty()) {
		printf("EMPTY\n");
	}
	else {
		printf("%d %d\n", pq[0], mq[0]);
	}
}

void getCommands(int cases) {
	priorityQ pq;
	int commands;
	char command;
	int num;
	for (int j = 0; j < cases; ++j) {
		scanf_s("%d", &commands);
		for (int i = 0; i < commands; ++i) {
			getchar();
			scanf_s("%c %d", &command, 1, &num);
			if (command == 'I') {
				pq.insert(num);
			}
			else {
				if (num < 0) {
					pq.popSmallest();
				}
				else {
					pq.popGreatest();
				}
			}
		}
		pq.print();
		pq.clear();
	}
}
int main() {
	int testCases;
	scanf_s("%d", &testCases);
	getCommands(testCases);
}