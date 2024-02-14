#include <iostream>
#include <vector>
#include <bitset>

struct rec {
	int smallerCase;
	int biggerCase;
	rec() {
		smallerCase = -1;
		biggerCase = -1;
	}
};

struct node {
	int num;
	node* prev;
	node* next;
};

class circList {
private:
	node* head;
	node* last;
public:
	circList(int size);
};

circList::circList(int size) {
	for (int i = 1; i <= size; ++i) {

	}
}

class zigZag {
private:
	std::bitset<101> visited;
	std::vector<std::vector<std::vector<rec>>> record;
	std::vector<std::pair<int, int>> biggerSmaller;
	int posCount;
	int size;
	void dfs(int depth, int num, bool bigger);
	void countPossiblity();
public:
	zigZag(int p_size);
};

zigZag::zigZag(int p_size) : size(p_size),
record(size + 1, std::vector<std::vector<rec>>(size, std::vector<rec>(size))),
biggerSmaller(size + 1) {
	int half = size >> 1;
	if (size % 2) ++half;
	for (int i = 1; i <= size; ++i) {
		biggerSmaller[i].first = size - i;
		biggerSmaller[i].second = size - biggerSmaller[i].first - 1;
	}
	int posCount = 0;
}

void zigZag::dfs(int depth, int num, bool bigger) {
	if (depth == size) {
		posCount = (posCount + 1) % 1000000;
		return;
	}
	if (bigger) {
		for (int i = num + 1; i <= size; ++i) {
			if (!visited[i]) {
				visited[i] = true;
				dfs(depth + 1, i, !bigger);
				visited[i] = false;
			}
		}
		return;
	}
	else {
		for (int i = num - 1; i >= 1; --i) {
			if (!visited[i]) {
				visited[i] = true;
				dfs(depth + 1, i, !bigger);
				visited[i] = false;
			}
		}
	}
}

void zigZag::countPossiblity() {
	if (size == 1) {
		posCount = 1;
		return;
	}
	for (int i = 1; i <= size; ++i) {
		visited[i] = true;
		dfs(1, i, true);
		dfs(1, i, false);
		visited[i] = false;
	}
}

int main() {
	int size = 0;
	scanf_s("%d", &size);

}
