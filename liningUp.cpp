#include <iostream>
#include <list>

struct node {
	int bigger;
	int count;
	int num;
};

int main() {
	std::list<node> line;
	int numb;
	scanf_s("%d", &numb);
	int in, count;
	for (int i = 1; i <= numb; ++i) {
		scanf_s("%d", &in);
		count = 0;
		auto it = line.begin();
		while (it != line.end()) {
			if (it->count < it->bigger) {
				line.insert(it, node{ in, count, i });
				break;
			}
		}
		while (it != line.end()) {
			if (it->count < it->bigger) {
				line.insert(it, node{ in, count, i });
				break;
			}
		}
	}
}