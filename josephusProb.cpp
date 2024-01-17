#include <iostream>
#include <vector>

struct node {
	int num;
	node* next;
	node* prev;
};

class circularList {
private:
	node* head;
	int count;
public:
	circularList() : head(nullptr) { count = 0; }
	void addNode(int num);
	void removeJosephus(int interval);
	~circularList();
};

void circularList::addNode(int num) {
	++count;
	if (head == nullptr) {
		head = new node;
		head->next = head;
		head->prev = head;
		head->num = num;
	}
	else {
		node* newOne = new node{ num, head, head->prev };
		head->prev->next = newOne;
		head->prev = newOne;
	}
}


void circularList::removeJosephus(int interval) {
	node* cur = head->prev;
	node* temp;
	bool first = true;
	while (count) {
		for (int i = 0; i < interval; ++i) {
			cur = cur->next;
		}
		if (first) {
			first = false;
			printf("<%d", cur->num);
		}
		else printf(", %d", cur->num);
		temp = cur;
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		cur = cur->prev;
		delete  temp;
		--count;
	}
	printf(">\n");
}

circularList::~circularList() {
	node* next;
	for (int i = 0; i < count; ++i) {
		next = head->next;
		delete head;
		head = next;
	}
}

int main() {
	int num, gap;
	scanf_s("%d %d", &num, &gap);
	circularList josephus;
	for (int i = 1; i <= num; ++i) {
		josephus.addNode(i);
	}
	josephus.removeJosephus(gap);

}
