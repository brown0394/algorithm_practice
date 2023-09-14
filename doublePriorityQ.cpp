#include <iostream>
#include <vector>

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
	~priorityQ();
};

priorityQ::~priorityQ() {
	pq.clear();
	mq.clear();
}

void priorityQ::swap(int& one, int& two) {
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
	while (true) {
		idxToCompare = idx << 1;
		if (idxToCompare > len) {
			break;
		}
		else {
			if (idxToCompare + 1 > len) {
				if (compare(isMaxQ, (*priorityq)[idx - 1], (*priorityq)[idxToCompare - 1])) {
					break;
				}
				childToSwap = idxToCompare;
			}
			else {
				if (compare(isMaxQ, (*priorityq)[idxToCompare - 1], (*priorityq)[idxToCompare])) {
					childToSwap = idxToCompare;
				}
				else {
					childToSwap = idxToCompare + 1;
				}
			}
			if (compare(isMaxQ, (*priorityq)[childToSwap - 1], (*priorityq)[idx - 1])) {
				swap((*priorityq)[childToSwap - 1], (*priorityq)[idx - 1]);
			}
			else {
				break;
			}
			idx = idxToCompare;
		}
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
	for (int i = priorityq->size() - 1; i >= 0; --i) {
		if ((*priorityq)[i] == num) {
			idx = i + 1;
			break;
		}
	}
	if (idx == priorityq->size()) {
		priorityq->pop_back();
		return num;
	}
	(*priorityq)[idx-1] = (*priorityq)[priorityq->size() - 1];
	priorityq->pop_back();
	int greaterChild;
	int idxToCompare;
	while (idx > 1) {
		idxToCompare = idx >> 1;
		if (compare(isMaxQ, (*priorityq)[idx - 1], (*priorityq)[idxToCompare - 1])) {
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

void getCommands() {
	priorityQ pq;
	int commands;
	scanf_s("%d", &commands);
	char command;
	int num;
	for (int i = 0; i < commands; ++i) {
		getchar();
		scanf_s("%c %d", &command, 1, &num);
		switch (command) {
		case 'I': {pq.insert(num); break; }
		case 'D': {
			if (num < 0) {
				pq.popSmallest();
			}
			else {
				pq.popGreatest();
			}
			break;
		}
		}
	}
	pq.print();
}
int main() {
	int testCases;
	scanf_s("%d", &testCases);
	for (int i = 0; i < testCases; ++i) {
		getCommands();
	}
}